#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QSharedDataPointer>
#include <QEnableSharedFromThis>
#include "Model/Model.h"
#include "Common/Commands.h"
#include "BuildGame2P_Command.h"
#include "BuildGame3P_Command.h"
#include "BuildGame4P_Command.h"
#include "BlockChange_Command.h"
#include "Player1_Down_Command.h"
#include "Player1_Left_Command.h"
#include "Player1_Right_Command.h"
#include "Player1_Up_Command.h"
#include "Player2_Down_Command.h"
#include "Player2_Left_Command.h"
#include "Player2_Right_Command.h"
#include "Player2_Up_Command.h"
#include "Player3_Down_Command.h"
#include "Player3_Left_Command.h"
#include "Player3_Right_Command.h"
#include "Player3_Up_Command.h"
#include "Player4_Down_Command.h"
#include "Player4_Left_Command.h"
#include "Player4_Right_Command.h"
#include "Player4_Up_Command.h"

class ViewModel
{
public:
    ViewModel(QSharedPointer<Model> &model) noexcept;

public:
    const QList<QList<Block>> GetBlocks();
    const QList<Player> GetPlayers();

public: // 执行函数
    void Exec_BuildGame2P_Command();
    void Exec_BuildGame3P_Command();
    void Exec_BuildGame4P_Command();
    void Exec_BlockChange_Command();

    void Exec_Player1_Down_Command();
    void Exec_Player1_Left_Command();
    void Exec_Player1_Right_Command();
    void Exec_Player1_Up_Command();

    void Exec_Player2_Down_Command();
    void Exec_Player2_Left_Command();
    void Exec_Player2_Right_Command();
    void Exec_Player2_Up_Command();

    void Exec_Player3_Down_Command();
    void Exec_Player3_Left_Command();
    void Exec_Player3_Right_Command();
    void Exec_Player3_Up_Command();

    void Exec_Player4_Down_Command();
    void Exec_Player4_Left_Command();
    void Exec_Player4_Right_Command();
    void Exec_Player4_Up_Command();

public: // 构造并绑定命令指针
    void Setup_Commands(QSharedPointer<ViewModel> &vm);

public: // 获取命令指针
    QSharedPointer<Commands> Get_BuildGame2P_Command();
    QSharedPointer<Commands> Get_BuildGame3P_Command();
    QSharedPointer<Commands> Get_BuildGame4P_Command();
    QSharedPointer<Commands> Get_BlockChange_Command();

    QSharedPointer<Commands> Get_Player1_Down_Command();
    QSharedPointer<Commands> Get_Player1_Left_Command();
    QSharedPointer<Commands> Get_Player1_Right_Command();
    QSharedPointer<Commands> Get_Player1_Up_Command();

    QSharedPointer<Commands> Get_Player2_Down_Command();
    QSharedPointer<Commands> Get_Player2_Left_Command();
    QSharedPointer<Commands> Get_Player2_Right_Command();
    QSharedPointer<Commands> Get_Player2_Up_Command();

    QSharedPointer<Commands> Get_Player3_Down_Command();
    QSharedPointer<Commands> Get_Player3_Left_Command();
    QSharedPointer<Commands> Get_Player3_Right_Command();
    QSharedPointer<Commands> Get_Player3_Up_Command();

    QSharedPointer<Commands> Get_Player4_Down_Command();
    QSharedPointer<Commands> Get_Player4_Left_Command();
    QSharedPointer<Commands> Get_Player4_Right_Command();
    QSharedPointer<Commands> Get_Player4_Up_Command();

private:
    // 指向对应模型的指针
    QSharedPointer<Model> m_model;

    // 指向各种命令的指针
    QSharedPointer<BuildGame2P_Command<ViewModel>> buildgame2p_command_;
    QSharedPointer<BuildGame3P_Command<ViewModel>> buildgame3p_command_;
    QSharedPointer<BuildGame4P_Command<ViewModel>> buildgame4p_command_;
    QSharedPointer<BlockChange_Command<ViewModel>> blockchange_command_;

    QSharedPointer<Player1_Down_Command<ViewModel>> player1_down_command_;
    QSharedPointer<Player1_Left_Command<ViewModel>> player1_left_command_;
    QSharedPointer<Player1_Right_Command<ViewModel>> player1_right_command_;
    QSharedPointer<Player1_Up_Command<ViewModel>> player1_up_command_;

    QSharedPointer<Player2_Down_Command<ViewModel>> player2_down_command_;
    QSharedPointer<Player2_Left_Command<ViewModel>> player2_left_command_;
    QSharedPointer<Player2_Right_Command<ViewModel>> player2_right_command_;
    QSharedPointer<Player2_Up_Command<ViewModel>> player2_up_command_;

    QSharedPointer<Player3_Down_Command<ViewModel>> player3_down_command_;
    QSharedPointer<Player3_Left_Command<ViewModel>> player3_left_command_;
    QSharedPointer<Player3_Right_Command<ViewModel>> player3_right_command_;
    QSharedPointer<Player3_Up_Command<ViewModel>> player3_up_command_;

    QSharedPointer<Player4_Down_Command<ViewModel>> player4_down_command_;
    QSharedPointer<Player4_Left_Command<ViewModel>> player4_left_command_;
    QSharedPointer<Player4_Right_Command<ViewModel>> player4_right_command_;
    QSharedPointer<Player4_Up_Command<ViewModel>> player4_up_command_;
};

#endif // VIEWMODEL_H
