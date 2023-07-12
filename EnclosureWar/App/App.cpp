#include "App.h"

App::App()
{
    model = QSharedPointer<Model>::create();
    view_model = QSharedPointer<ViewModel>::create(model);
    view_model->Setup_Commands(view_model);
    view = QSharedPointer<View>::create();


}

void App::run()
{
    view->show();
}
