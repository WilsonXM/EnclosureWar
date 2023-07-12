#ifndef PLAYER2_UP_COMMAND_H
#define PLAYER2_UP_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class Player2_Up_Command :public Commands
{
public:
    Player2_Up_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_Player2_Up_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
