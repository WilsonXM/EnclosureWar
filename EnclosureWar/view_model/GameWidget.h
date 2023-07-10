#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
//#include "model/Paint.h"

class GameWidget : public QWidget
{
public:
    explicit GameWidget(QWidget *parent = nullptr);
    //void SetPaint(Paint *p) { paint = p; }
    void ReSize(int width, int height);

signals:
    void sigUpdateScore(int nScore);

//protected:
    //void paintEvent(QPaintEvent *);

private:
    //Paint *paint;
};

#endif // GAMEWIDGET_H
