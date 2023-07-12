#ifndef PLAYER2_RIGHT_COMMAND_H
#define PLAYER2_RIGHT_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class Player2_Right_Command :public Commands
{
public:
    Player2_Right_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_Player2_Right_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
