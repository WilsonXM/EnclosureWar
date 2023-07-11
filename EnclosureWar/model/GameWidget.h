#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPainter>
#include "common/Block.h"

extern int x_;
extern int y_;

class GameWidget : public QWidget
{
public:
    explicit GameWidget(QWidget *parent = nullptr);
    void SetBlocks(QList<QList<Block>> *bls) { blocks = bls; }
    void DrawBlock(Block block, Color color);
    void DrawBlocks();      // 画整个游戏区域

signals:
    void sigUpdateScore(int nScore);

protected:
    void paintEvent(QPaintEvent *);

private:
    QList<QList<Block>> *blocks;
};

#endif // GAMEWIDGET_H






