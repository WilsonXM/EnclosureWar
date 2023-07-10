#include "view/initwindow.h"

#include <QApplication>
#include <QSoundEffect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initwindow w;
    w.show();

    // music
    QSoundEffect *music = new QSoundEffect();
    music->setSource(QUrl::fromLocalFile(":/music/Bach.wav"));
    music->setLoopCount(QSoundEffect::Infinite);  //设置无限循环
    music->setVolume(0.5f);  //设置音量，在0到1之间
    music->play();

    return a.exec();
}
