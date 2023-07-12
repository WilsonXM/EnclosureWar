#ifndef MAP_UI_H
#define MAP_UI_H

#include <QPaintEvent>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include "Common/Block.h"

class Map_ui : public QWidget
{
    Q_OBJECT
public:
    explicit Map_ui(QWidget *parent = nullptr);
    void paint(QPainter &,int width, int height);
    void set_blocks_colors();

private:
    QSharedPointer<QList<QList<Block>>> blocks_colors;
};

#endif // MAP_UI_H
