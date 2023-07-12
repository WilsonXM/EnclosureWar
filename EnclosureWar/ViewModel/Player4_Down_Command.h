#ifndef PLAYER4_DOWN_COMMAND_H
#define PLAYER4_DOWN_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class Player4_Down_Command :public Commands
{
public:
    Player4_Down_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_Player4_Down_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
