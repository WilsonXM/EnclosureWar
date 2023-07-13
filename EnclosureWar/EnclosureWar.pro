QT       += core gui
QT       += multimedia
CONFIG   += resources_big
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Common/Common.cpp \
    Common/Block.cpp \
    Model/Model.cpp \
    Common/Player.cpp \
    View/ClockLabel_ui.cpp \
    View/Map_ui.cpp \
    View/MusicButton_ui.cpp \
    View/PauseButton_ui.cpp \
    View/ScoreLabel_ui.cpp \
    Model/Map.cpp \
    View/View.cpp \
    ViewModel/ViewModel.cpp \
    App/App.cpp \
    main.cpp

HEADERS += \
    Common/Commands.h \
    Common/Common.h \
    Common/Block.h \
    Model/Model.h \
    Common/Player.h \
    View/ClockLabel_ui.h \
    View/Map_ui.h \
    View/MusicButton_ui.h \
    View/PauseButton_ui.h \
    View/ScoreLabel_ui.h \
    Model/Map.h \
    View/View.h \
    ViewModel/ViewModel.h \
    ViewModel/BuildGame2P_Command.h \
    ViewModel/BuildGame3P_Command.h \
    ViewModel/BuildGame4P_Command.h \
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

RESOURCES += \
    Source/Resources.qrc
