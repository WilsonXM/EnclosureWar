#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QList>
#include <QSet>
#include "Common/Commands.h"
#include "View/Map_ui.h"
#include "Common/Common.h"
#include "View/ScoreLabel_ui.h"
#include "View/MusicButton_ui.h"
#include "View/PauseButton_ui.h"
#include "View/ClockLabel_ui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

    // 绑定命令的方法
    void set_build_2p_command(QSharedPointer<Commands>);
    void set_build_3p_command(QSharedPointer<Commands>);
    void set_build_4p_command(QSharedPointer<Commands>);
    void set_move_command(QSharedPointer<Commands>);        // 修改blocks数据
    void set_player1_up_command(QSharedPointer<Commands>);
    void set_player1_down_command(QSharedPointer<Commands>);
    void set_player1_left_command(QSharedPointer<Commands>);
    void set_player1_right_command(QSharedPointer<Commands>);
    void set_player2_up_command(QSharedPointer<Commands>);
    void set_player2_down_command(QSharedPointer<Commands>);
    void set_player2_left_command(QSharedPointer<Commands>);
    void set_player2_right_command(QSharedPointer<Commands>);
    void set_player3_up_command(QSharedPointer<Commands>);
    void set_player3_down_command(QSharedPointer<Commands>);
    void set_player3_left_command(QSharedPointer<Commands>);
    void set_player3_right_command(QSharedPointer<Commands>);
    void set_player4_up_command(QSharedPointer<Commands>);
    void set_player4_down_command(QSharedPointer<Commands>);
    void set_player4_left_command(QSharedPointer<Commands>);
    void set_player4_right_command(QSharedPointer<Commands>);


    // 获取blocks信息的方法
    void set_get_blocks_colors(const std::function<QSharedPointer<QList<QList<Block>>>&&(void)>);


    // 获取/设置游戏时间
    int get_GameTime() { return gametime; }
    void set_GameTime(const int time) { gametime = time; }

protected:
    void keyPressEvent(QKeyEvent *event) override; // 键盘按下事件
    void keyReleaseEvent(QKeyEvent *event) override; // 键盘松开事件
    void paintEvent(QPaintEvent *) override; // 绘制事件，通过update()函数激活
    void mousePressEvent(QMouseEvent *event) override; // 鼠标点击时间

signals:
    void pause_signal(const GameState &status); // 发送暂停信号

private slots:
    void move(); // 每隔一段时间就触发move_command

public slots: // 槽函数
    void react_game_status_change(const GameState &status); // 接收游戏状态改变的信号

private:
    Ui::View *ui;
    QSet<Qt::Key> keys_pressed; // 被按下的所有按键
    int gametime = 60;      // 单位是秒(s)

    // 游戏界面背景
    QPixmap background;

    // ui组件
    QSharedPointer<Map_ui> map;
    QSharedPointer<PauseButton_ui> pausebutton;
    QSharedPointer<MusicButton_ui> musicbutton;
    QSharedPointer<ClockLabel_ui> clocklabel;
    QList<QSharedPointer<ScoreLabel_ui>> scorelabels;    // 显示用户当前成绩的标签

    // 命令s
    QSharedPointer<Commands> build_2p_command;
    QSharedPointer<Commands> build_3p_command;
    QSharedPointer<Commands> build_4p_command;
    QSharedPointer<Commands> move_command;           // 修改blocks数据
    QSharedPointer<Commands> player1_up_command;     // 玩家1上移指令
    QSharedPointer<Commands> player1_down_command;   // 玩家1下移指令
    QSharedPointer<Commands> player1_left_command;   // 玩家1左移指令
    QSharedPointer<Commands> player1_right_command;  // 玩家1右移指令
    QSharedPointer<Commands> player2_up_command;     // 玩家2上移指令
    QSharedPointer<Commands> player2_down_command;   // 玩家2下移指令
    QSharedPointer<Commands> player2_left_command;   // 玩家2左移指令
    QSharedPointer<Commands> player2_right_command;  // 玩家2右移指令
    QSharedPointer<Commands> player3_up_command;     // 玩家3上移指令
    QSharedPointer<Commands> player3_down_command;   // 玩家3下移指令
    QSharedPointer<Commands> player3_left_command;   // 玩家3左移指令
    QSharedPointer<Commands> player3_right_command;  // 玩家3右移指令
    QSharedPointer<Commands> player4_up_command;     // 玩家4上移指令
    QSharedPointer<Commands> player4_down_command;   // 玩家4下移指令
    QSharedPointer<Commands> player4_left_command;   // 玩家4左移指令
    QSharedPointer<Commands> player4_right_command;  // 玩家4右移指令

    // 获取所有blocks的染色信息
    std::function<QSharedPointer<QList<QList<Block>>>(void)> get_blocks_colors;

    // 定时器
    QTimer *timer;
    GameState game_status; // 游戏状态
};
#endif // VIEW_H
