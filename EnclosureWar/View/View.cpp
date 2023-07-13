#include "View.h"
#include "ui_view.h"

#include <QDialog>
#include <QFormLayout>
#include <QSpinBox>
#include <QProcess>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
#include <QDialogButtonBox>
#include <QDebug>

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , timer(new QTimer(this)) // 定时器
    , game_state(PLAYING)
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
    spinbox2->setSuffix(QString("min"));
    form.addRow(value2, spinbox2);
    // Add Cancel and OK button
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Process when Rejected button is clicked
    if (dialog.exec() == QDialog::Rejected)
        this->close();

    // 初始化共享指针
    pausebutton = static_cast<QSharedPointer<PauseButton_ui>>(ui->pausebutton);
    musicbutton = static_cast<QSharedPointer<MusicButton_ui>>(ui->musicbutton);

    //      初始化倒计时，并赋初值
    gametime = spinbox2->value();
    total_sec = gametime * 60;
    clocklabel = static_cast<QSharedPointer<ClockLabel_ui>>(ui->clock);
    char GameTime_left[10];
    sprintf(GameTime_left, "%d", gametime);
    ui->clock->setText(QString(GameTime_left) + QString(" :") + QString(" 0 0"));


    //      初始化分值标签，赋初值，并根据人数显示
    pNum = spinbox1->value();
    if(pNum <= 1) this->close();
    ui->playerlabel_3->setVisible(false);
    ui->playerlabel_4->setVisible(false);

    scorelabels.push_back(static_cast<QSharedPointer<ScoreLabel_ui>>(ui->scorelabel_1));
    scorelabels[0]->setText(QString("0"));
    scorelabels[0]->setVisible(true);
    ui->playerlabel_1->setVisible(true);

    scorelabels.push_back(static_cast<QSharedPointer<ScoreLabel_ui>>(ui->scorelabel_2));
    scorelabels[1]->setText(QString("0"));
    scorelabels[1]->setVisible(true);
    ui->playerlabel_2->setVisible(true);

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

    // 开始时钟
    timer->start(GCD);
    setFocusPolicy(Qt::StrongFocus);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // 连接暂停信号
    connect(this, &View::pause_signal, this, &View::react_game_status_change);

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

void View::react_game_status_change(const GameState &status) // 接收游戏状态改变的信号
{
    if(status == TIMEOUT) {
        // 断开连接函数
        disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));

        // 创建弹窗
        auto msg_box = QSharedPointer<QMessageBox>::create();
        msg_box->setIcon(QMessageBox::Information);
        // tr是为了显示中文
        msg_box->setWindowTitle(tr("提示")); // 设置弹窗标题
        msg_box->setText(tr("倒计时结束，是否重新游戏？")); // 设置弹窗信息
        msg_box->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msg_box->setDefaultButton(QMessageBox::Yes);
        msg_box->button(QMessageBox::Yes)->setText(tr("重启")); // 设置弹窗按钮的文字
        msg_box->button(QMessageBox::No)->setText(tr("退出"));

        msg_box->show();
        // click_result判断用户点击了什么按钮
        auto click_result = msg_box->exec();
        if (click_result == QMessageBox::Yes)
        {
            QString program = QApplication::applicationFilePath();
            QStringList arguments = QApplication::arguments();
            QString workingDirectory = QDir::currentPath();
            QProcess::startDetached(program, arguments, workingDirectory);
            QApplication::exit();
        }
        else if (click_result == QMessageBox::No)
        {
            this->close();
        }
    } else if (status == PAUSE) {
        if (game_state == PAUSE)
        { // 正在暂停
            connect(timer, SIGNAL(timeout()), this, SLOT(move())); // 重连计时器
            game_state = PLAYING; // 修改游戏状态
        }
        else if (game_state == PLAYING) {
            // 清除所有按键
            keys_pressed.clear();

            // 断开计时器连接
            disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));
            game_state = PAUSE;

            // 创建弹窗
            auto msg_box = QSharedPointer<QMessageBox>::create();
            msg_box->setIcon(QMessageBox::Information);
            // tr是为了显示中文
            msg_box->setWindowTitle(tr("提示")); // 设置弹窗标题
            msg_box->setText(tr("游戏暂停")); // 设置弹窗信息
                msg_box->setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Save);
            msg_box->setDefaultButton(QMessageBox::Save);
            msg_box->button(QMessageBox::Yes)->setText(tr("重启游戏")); // 设置弹窗按钮的文字
            msg_box->button(QMessageBox::No)->setText(tr("退出"));
            msg_box->button(QMessageBox::Save)->setText(tr("继续游戏"));

            msg_box->show();
            // click_result判断用户点击了什么按钮
            auto click_result = msg_box->exec();
            if (click_result == QMessageBox::Yes)
            {
                QString program = QApplication::applicationFilePath();
                QStringList arguments = QApplication::arguments();
                QString workingDirectory = QDir::currentPath();
                QProcess::startDetached(program, arguments, workingDirectory);
                QApplication::exit();
            }
            else if (click_result == QMessageBox::No)
            {
                this->close();
            }
            else if (click_result == QMessageBox::Save)
            { // 继续游戏
                emit pause_signal(PAUSE);
            }
        }
    }
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
    if (keys_pressed.contains(Qt::Key_Return))
    {
        emit pause_signal(PAUSE);
    }

    move_command->exec();

    // 实现倒计时
    single_sec++;
    if(single_sec == 20) {
        single_sec = 0;
        total_sec--;
        char minute[3], second[3];
        int seconds = total_sec % 60;
        int minutes = total_sec / 60;
        sprintf(second, "%d", seconds);
        sprintf(minute, "%d", minutes);
        ui->clock->setText( QString(minute) + QString(" : ") + QString(second));
        if(minutes <= 0 && seconds <= 0)
            emit pause_signal(TIMEOUT);
    }

    update();
}

void View::on_pausebutton_clicked()
{
    emit pause_signal(PAUSE);
}


void View::on_musicbutton_clicked()
{
    emit music_signal(STOP);
}

