#ifndef PLAYER1_RIGHT_COMMAND_H
#define PLAYER1_RIGHT_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class Player1_Right_Command :public Commands
{
public:
    Player1_Right_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_Player1_Right_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
