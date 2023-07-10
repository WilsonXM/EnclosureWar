#ifndef INITWINDOW_H
#define INITWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {class initwindow;}
QT_END_NAMESPACE

class initwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit initwindow(QWidget *parent = nullptr);

    void switchPage();
    ~initwindow();

private slots:


    void on_commitButton_clicked();

private:
    Ui::initwindow *initwin;
};

#endif // INITWINDOW_H
