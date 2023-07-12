#include "ViewModel.h"
#include "./common/Common.h"
#include <QDebug>

ViewModel::ViewModel(QSharedPointer<Model> &model) noexcept { m_model = model; }

void ViewModel::Exec_BuildGame_Command() { ; }

void ViewModel::Exec_Move_Command() { ; }

void ViewModel::Exec_Player1_Down_Command() { ; }

void ViewModel::Exec_Player1_Left_Command() { ; }

void ViewModel::Exec_Player1_Right_Command() { ; }

void ViewModel::Exec_Player1_Up_Command() { ; }

void ViewModel::Exec_Player2_Down_Command() { ; }

void ViewModel::Exec_Player2_Left_Command() { ; }

void ViewModel::Exec_Player2_Right_Command() { ; }

void ViewModel::Exec_Player2_Up_Command() { ; }

void ViewModel::Exec_Player3_Down_Command() { ; }

void ViewModel::Exec_Player3_Left_Command() { ; }

void ViewModel::Exec_Player3_Right_Command() { ; }

void ViewModel::Exec_Player3_Up_Command() { ; }

void ViewModel::Exec_Player4_Down_Command() { ; }

void ViewModel::Exec_Player4_Left_Command() { ; }

void ViewModel::Exec_Player4_Right_Command() { ; }

void ViewModel::Exec_Player4_Up_Command() { ; }

void ViewModel::Setup_Commands(QSharedPointer<ViewModel> &vm)
{
    buildgame_command_ = QSharedPointer<BuildGame_Command<ViewModel>>::create(vm);
    move_command_ = QSharedPointer<Move_Command<ViewModel>>::create(vm);

    player1_down_command_ = QSharedPointer<Player1_Down_Command<ViewModel>>::create(vm);
    player1_left_command_ = QSharedPointer<Player1_Left_Command<ViewModel>>::create(vm);
    player1_right_command_ = QSharedPointer<Player1_Right_Command<ViewModel>>::create(vm);
    player1_up_command_ = QSharedPointer<Player1_Up_Command<ViewModel>>::create(vm);

    player2_down_command_ = QSharedPointer<Player2_Down_Command<ViewModel>>::create(vm);
    player2_left_command_ = QSharedPointer<Player2_Left_Command<ViewModel>>::create(vm);
    player2_right_command_ = QSharedPointer<Player2_Right_Command<ViewModel>>::create(vm);
    player2_up_command_ = QSharedPointer<Player2_Up_Command<ViewModel>>::create(vm);

    player3_down_command_ = QSharedPointer<Player3_Down_Command<ViewModel>>::create(vm);
    player3_left_command_ = QSharedPointer<Player3_Left_Command<ViewModel>>::create(vm);
    player3_right_command_ = QSharedPointer<Player3_Right_Command<ViewModel>>::create(vm);
    player3_up_command_ = QSharedPointer<Player3_Up_Command<ViewModel>>::create(vm);

    player4_down_command_ = QSharedPointer<Player4_Down_Command<ViewModel>>::create(vm);
    player4_left_command_ = QSharedPointer<Player4_Left_Command<ViewModel>>::create(vm);
    player4_right_command_ = QSharedPointer<Player4_Right_Command<ViewModel>>::create(vm);
    player4_up_command_ = QSharedPointer<Player4_Up_Command<ViewModel>>::create(vm);
}

QSharedPointer<Commands> ViewModel::Get_BuildGame_Command() { return buildgame_command_; }

QSharedPointer<Commands> ViewModel::Get_Move_Command() { return move_command_; }

QSharedPointer<Commands> ViewModel::Get_Player1_Down_Command() { return player1_down_command_; }

QSharedPointer<Commands> ViewModel::Get_Player1_Left_Command() { return player1_left_command_; }

QSharedPointer<Commands> ViewModel::Get_Player1_Right_Command() { return player1_right_command_; }

QSharedPointer<Commands> ViewModel::Get_Player1_Up_Command() { return player1_up_command_; }

QSharedPointer<Commands> ViewModel::Get_Player2_Down_Command() { return player2_down_command_; }

QSharedPointer<Commands> ViewModel::Get_Player2_Left_Command() { return player2_left_command_; }

QSharedPointer<Commands> ViewModel::Get_Player2_Right_Command() { return player2_right_command_; }

QSharedPointer<Commands> ViewModel::Get_Player2_Up_Command() { return player2_up_command_; }

QSharedPointer<Commands> ViewModel::Get_Player3_Down_Command() { return player3_down_command_; }

QSharedPointer<Commands> ViewModel::Get_Player3_Left_Command() { return player3_left_command_; }

QSharedPointer<Commands> ViewModel::Get_Player3_Right_Command() { return player3_right_command_; }

QSharedPointer<Commands> ViewModel::Get_Player3_Up_Command() { return player3_up_command_; }

QSharedPointer<Commands> ViewModel::Get_Player4_Down_Command() { return player4_down_command_; }

QSharedPointer<Commands> ViewModel::Get_Player4_Left_Command() { return player4_left_command_; }

QSharedPointer<Commands> ViewModel::Get_Player4_Right_Command() { return player4_right_command_; }

QSharedPointer<Commands> ViewModel::Get_Player4_Up_Command() { return player4_up_command_; }







