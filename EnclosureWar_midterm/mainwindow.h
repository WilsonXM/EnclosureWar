#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *e);

private slots:
    void slotUpdateScore(int nScore);

private:
    int GetHistoryMaxScore();
    void SaveHistoryMaxScore(int nScore);

private:
    Ui::MainWindow *ui;

};

#endif
