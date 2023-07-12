QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    App/App.cpp \
    Common/Common.cpp \
    Model/Block.cpp \
    Model/Model.cpp \
    Model/Player.cpp \
    View/ClockLabel_ui.cpp \
    View/Map_ui.cpp \
    View/MusicButton_ui.cpp \
    View/PauseButton_ui.cpp \
    View/ScoreLabel_ui.cpp \
    ViewModel/ViewModel.cpp \
    main.cpp \
    View/View.cpp

HEADERS += \
    App/App.h \
    Common/Commands.h \
    Common/Common.h \
    Model/Block.h \
    Model/Model.h \
    Model/Player.h \
    View/ClockLabel_ui.h \
    View/Map_ui.h \
    View/MusicButton_ui.h \
    View/PauseButton_ui.h \
    View/ScoreLabel_ui.h \
    View/View.h \
    ViewModel/ViewModel.h

FORMS += \
    View/view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
