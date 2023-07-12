QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Common/Common.cpp \
    Model/Block.cpp \
    Model/Map.cpp \
    Model/Model.cpp \
    Model/Player.cpp \
    View/View.cpp \
    ViewModel/ViewModel.cpp \
    App/App.cpp \
    main.cpp

HEADERS += \
    Common/Commands.h \
    Common/Common.h \
    Model/Block.h \
    Model/Map.h \
    Model/Model.h \
    Model/Player.h \
    View/View.h \
    ViewModel/ViewModel.h \
    ViewModel/BuildGame_Command.h \
    ViewModel/Move_Command.h \
    ViewModel/Player1_Left_Command.h \
    ViewModel/Player1_Right_Command.h \
    ViewModel/Player1_Up_Command.h \
    ViewModel/Player1_Down_Command.h \
    ViewModel/Player2_Left_Command.h \
    ViewModel/Player2_Right_Command.h \
    ViewModel/Player2_Up_Command.h \
    ViewModel/Player2_Down_Command.h \
    ViewModel/Player3_Left_Command.h \
    ViewModel/Player3_Right_Command.h \
    ViewModel/Player3_Up_Command.h \
    ViewModel/Player3_Down_Command.h \
    ViewModel/Player4_Left_Command.h \
    ViewModel/Player4_Right_Command.h \
    ViewModel/Player4_Up_Command.h \
    ViewModel/Player4_Down_Command.h \
    App/App.h

FORMS += \
    View/view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
