#ifndef PLAYER4_UP_COMMAND_H
#define PLAYER4_UP_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class Player4_Up_Command :public Commands
{
public:
    Player4_Up_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_Player4_Up_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
