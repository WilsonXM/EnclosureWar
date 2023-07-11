#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "Common/Commands.h"

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
    void set_game_status_command(QSharedPointer<Commands>);
    void set_player_up_command(QSharedPointer<Commands>);
    void set_player_down_command(QSharedPointer<Commands>);
    void set_player_left_command(QSharedPointer<Commands>);
    void set_player_right_command(QSharedPointer<Commands>);
    void set_music_command(QSharedPointer<Commands>);

    /*
    // 绑定仿函数的方法
    void set_get_ice_pos(const std::function<QPointF(void)>&&);
    void set_get_fire_pos(const std::function<QPointF(void)>&&);
    void set_get_ice_speed(const std::function<QPointF(void)>&&);
    void set_get_fire_speed(const std::function<QPointF(void)>&&);
    */

private:
    Ui::View *ui;
};
#endif // VIEW_H
