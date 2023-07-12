#include "App.h"

App::App()
{
    view = QSharedPointer<View>::create();
}

void App::run()
{
    view->show();
}
