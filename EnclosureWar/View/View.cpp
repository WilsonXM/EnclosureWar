#include "View.h"
#include "ui_view.h"

#include <QDialog>
#include <QFormLayout>
#include <QSpinBox>
#include <QDialogButtonBox>

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , timer(new QTimer(this)) // 定时器
    , game_status(PLAYING)
{
    ui->setupUi(this);

    QDialog dialog(this);
    QFormLayout form(&dialog);
    form.addRow(new QLabel("游戏设置"));
    // Value1
    QString value1 = QString("游戏人数: ");
    QSpinBox *spinbox1 = new QSpinBox(&dialog);
    form.addRow(value1, spinbox1);
    // Value2
    QString value2 = QString("游戏时间: ");
    QSpinBox *spinbox2 = new QSpinBox(&dialog);
    spinbox2->setSuffix(QString("s"));
    form.addRow(value2, spinbox2);
    // Add Cancel and OK button
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Process when Rejected button is clicked
    if (dialog.exec() == QDialog::Rejected)
        QTimer::singleShot(0, qApp, SLOT(quit()));

    // 初始化共享指针
    pausebutton = static_cast<QSharedPointer<PauseButton_ui>>(ui->pausebutton);
    musicbutton = static_cast<QSharedPointer<MusicButton_ui>>(ui->musicbutton);

    //      初始化倒计时，并赋初值
    gametime = spinbox2->value();
    clocklabel = static_cast<QSharedPointer<ClockLabel_ui>>(ui->clock);
    clocklabel->setText(QString(gametime) + QString("s"));

    //      初始化分值标签，赋初值，并根据人数显示
    pNum = spinbox1->value();
    if(pNum >= 1) {
        scorelabels.push_back(static_cast<QSharedPointer<ScoreLabel_ui>>(ui->scorelabel_1));
        scorelabels[0]->setText(QString("0"));
        scorelabels[0]->setVisible(true);
        ui->playerlabel_1->setVisible(true);
    }
    if(pNum >= 2) {
        scorelabels.push_back(static_cast<QSharedPointer<ScoreLabel_ui>>(ui->scorelabel_2));
        scorelabels[1]->setText(QString("0"));
        scorelabels[1]->setVisible(true);
        ui->playerlabel_2->setVisible(true);
    }
    if(pNum >= 3) {
        scorelabels.push_back(static_cast<QSharedPointer<ScoreLabel_ui>>(ui->scorelabel_3));
        scorelabels[2]->setText(QString("0"));
        scorelabels[2]->setVisible(true);
        ui->playerlabel_3->setVisible(true);
    }
    if(pNum >= 4) {
        scorelabels.push_back(static_cast<QSharedPointer<ScoreLabel_ui>>(ui->scorelabel_4));
        scorelabels[3]->setText(QString("0"));
        scorelabels[3]->setVisible(true);
        ui->playerlabel_4->setVisible(true);
    }

    // 初始化共享指针map
    map = static_cast<QSharedPointer<Map_ui>>(ui->map_ui);

    timer->start(GCD);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    this->setFixedSize(1300, 800);
}

View::~View()
{
    delete ui;
}

// 绑定指令的方法
void View::set_build_2p_command(QSharedPointer<Commands> command)
{
    build_2p_command = command;
}
void View::set_build_3p_command(QSharedPointer<Commands> command)
{
    build_3p_command = command;
}
void View::set_build_4p_command(QSharedPointer<Commands> command)
{
    build_4p_command = command;
}
void View::set_move_command(QSharedPointer<Commands> command)      // 修改blocks数据
{
    move_command = command;
}
void View::set_player1_up_command(QSharedPointer<Commands> command)
{
    player1_up_command = command;
}
void View::set_player1_down_command(QSharedPointer<Commands> command)
{
    player1_down_command = command;
}
void View::set_player1_left_command(QSharedPointer<Commands> command)
{
    player1_left_command = command;
}
void View::set_player1_right_command(QSharedPointer<Commands> command)
{
    player1_right_command = command;
}
void View::set_player2_up_command(QSharedPointer<Commands> command)
{
    player2_up_command = command;
}
void View::set_player2_down_command(QSharedPointer<Commands> command)
{
    player2_down_command = command;
}
void View::set_player2_left_command(QSharedPointer<Commands> command)
{
    player2_left_command = command;
}
void View::set_player2_right_command(QSharedPointer<Commands> command)
{
    player2_right_command = command;
}
void View::set_player3_up_command(QSharedPointer<Commands> command)
{
    player3_up_command = command;
}
void View::set_player3_down_command(QSharedPointer<Commands> command)
{
    player3_down_command = command;
}
void View::set_player3_left_command(QSharedPointer<Commands> command)
{
    player3_left_command = command;
}
void View::set_player3_right_command(QSharedPointer<Commands> command)
{
    player3_right_command = command;
}
void View::set_player4_up_command(QSharedPointer<Commands> command)
{
    player4_up_command = command;
}
void View::set_player4_down_command(QSharedPointer<Commands> command)
{
    player4_down_command = command;
}
void View::set_player4_left_command(QSharedPointer<Commands> command)
{
    player4_left_command = command;
}
void View::set_player4_right_command(QSharedPointer<Commands> command)
{
    player4_right_command = command;
}

// 获取blocks信息的方法
void View::set_get_blocks_colors(const std::function<QList<QList<Block>>(void)> func)
{
    get_blocks_colors = func;
}

void View::keyPressEvent(QKeyEvent *event)
{
    keys_pressed += Qt::Key(event->key());
    /* 1.游戏暂停 */
    if (keys_pressed.contains(Qt::Key_Space))
        emit pause_signal(PAUSE);
}
void View::keyReleaseEvent(QKeyEvent *event)
{
    if (!keys_pressed.isEmpty())
        keys_pressed -= Qt::Key(event->key());
}

void View::paintEvent(QPaintEvent *)
{
    QPainter painter(this); // 构建画笔

    // 绘制地图
    map->set_blocks_colors(get_blocks_colors());
    map->paint(painter, 100, 75);

    update();

}

void View::move()
{
    if (keys_pressed.contains(Qt::Key_A))
    {
        player1_left_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_D))
    {
        player1_right_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_W))
    {
        player1_up_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_S))
    {
        player1_down_command->exec();
    }

    if (keys_pressed.contains(Qt::Key_Left))
    {
        player2_left_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_Right))
    {
        player2_right_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_Up))
    {
        player2_up_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_Down))
    {
        player2_down_command->exec();
    }

    if (keys_pressed.contains(Qt::Key_5))
    {
        player3_up_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_3))
    {
        player3_right_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_1))
    {
        player3_left_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_2))
    {
        player3_down_command->exec();
    }

    if (keys_pressed.contains(Qt::Key_I))
    {
        player4_up_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_L))
    {
        player4_right_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_J))
    {
        player4_left_command->exec();
    }
    if (keys_pressed.contains(Qt::Key_K))
    {
        player4_down_command->exec();
    }

    move_command->exec();
    update();
}
