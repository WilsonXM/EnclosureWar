#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "view_model/GameWidget.h"
#include "view_model/Game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, int width = 10, int height = 10, int pnum = 1);
    //void SetWidth(int w) { width_ = w; }
    //void SetHeight(int h) { height_ = h; }
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *e);

private slots:
    void slotUpdateScore(int nScore);

private:
    Ui::MainWindow *mainwin;
    int width_;
    int height_;
    int pnum_;
    Game *game;
};
#endif // MAINWINDOW_H
