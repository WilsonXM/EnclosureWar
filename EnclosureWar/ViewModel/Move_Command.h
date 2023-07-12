#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class Move_Command :public Commands
{
public:
    Move_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_Move_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
