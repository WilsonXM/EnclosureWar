#include "App/App.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App app;
    app.run();
    return a.exec();
}
