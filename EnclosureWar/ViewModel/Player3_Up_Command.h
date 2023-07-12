#ifndef PLAYER3_UP_COMMAND_H
#define PLAYER3_UP_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class Player3_Up_Command :public Commands
{
public:
    Player3_Up_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_Player3_Up_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
