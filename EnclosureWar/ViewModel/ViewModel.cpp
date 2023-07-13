#include "ViewModel.h"

ViewModel::ViewModel(QSharedPointer<Model> &model) noexcept { m_model = model; }

const QList<QList<Block>> ViewModel::GetBlocks() { return m_model->map->GetBlocks(); }

const QList<Player> ViewModel::GetPlayers() { return m_model->map->GetPlayers(); }

void ViewModel::Exec_BuildGame2P_Command() { m_model->BuildGame(2); }

void ViewModel::Exec_BuildGame3P_Command() { m_model->BuildGame(3); }

void ViewModel::Exec_BuildGame4P_Command() { m_model->BuildGame(4); }

void ViewModel::Exec_BlockChange_Command() { m_model->Move(); }

void ViewModel::Exec_Player1_Down_Command() { m_model->PlayerMove(1, Move::DOWN); }

void ViewModel::Exec_Player1_Left_Command() { m_model->PlayerMove(1, Move::LEFT); }

void ViewModel::Exec_Player1_Right_Command() { m_model->PlayerMove(1, Move::RIGHT); }

void ViewModel::Exec_Player1_Up_Command() { m_model->PlayerMove(1, Move::UP); }

void ViewModel::Exec_Player2_Down_Command() { m_model->PlayerMove(2, Move::DOWN); }

void ViewModel::Exec_Player2_Left_Command() { m_model->PlayerMove(2, Move::LEFT); }

void ViewModel::Exec_Player2_Right_Command() { m_model->PlayerMove(2, Move::RIGHT); }

void ViewModel::Exec_Player2_Up_Command() { m_model->PlayerMove(2, Move::UP); }

void ViewModel::Exec_Player3_Down_Command() { m_model->PlayerMove(3, Move::DOWN); }

void ViewModel::Exec_Player3_Left_Command() { m_model->PlayerMove(3, Move::LEFT); }

void ViewModel::Exec_Player3_Right_Command() { m_model->PlayerMove(3, Move::RIGHT); }

void ViewModel::Exec_Player3_Up_Command() { m_model->PlayerMove(3, Move::UP); }

void ViewModel::Exec_Player4_Down_Command() { m_model->PlayerMove(4, Move::DOWN); }

void ViewModel::Exec_Player4_Left_Command() { m_model->PlayerMove(4, Move::LEFT); }

void ViewModel::Exec_Player4_Right_Command() { m_model->PlayerMove(4, Move::RIGHT); }

void ViewModel::Exec_Player4_Up_Command() { m_model->PlayerMove(4, Move::UP); }

void ViewModel::Setup_Commands(QSharedPointer<ViewModel> &vm)
{
    buildgame2p_command_ = QSharedPointer<BuildGame2P_Command<ViewModel>>::create(vm);
    buildgame3p_command_ = QSharedPointer<BuildGame3P_Command<ViewModel>>::create(vm);
    buildgame4p_command_ = QSharedPointer<BuildGame4P_Command<ViewModel>>::create(vm);
    blockchange_command_ = QSharedPointer<BlockChange_Command<ViewModel>>::create(vm);

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

QSharedPointer<Commands> ViewModel::Get_BuildGame2P_Command() { return buildgame2p_command_; }

QSharedPointer<Commands> ViewModel::Get_BuildGame3P_Command() { return buildgame3p_command_; }

QSharedPointer<Commands> ViewModel::Get_BuildGame4P_Command() { return buildgame4p_command_; }

QSharedPointer<Commands> ViewModel::Get_BlockChange_Command() { return blockchange_command_; }

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







