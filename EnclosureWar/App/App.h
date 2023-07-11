#ifndef APP_H
#define APP_H


#include <QObject>
#include <QSharedPointer>
#include "View/View.h"
#include "ViewModel/ViewModel.h"
#include "Model/Model.h"

class App : public QObject
{
    Q_OBJECT
public:
    App();
    void run();

private:
    QSharedPointer<View> view;
    QSharedPointer<Model> model;
    QSharedPointer<ViewModel> view_model;
};

#endif // APP_H
