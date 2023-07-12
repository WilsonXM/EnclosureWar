#ifndef PLAYER4_LEFT_COMMAND_H
#define PLAYER4_LEFT_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class Player4_Left_Command :public Commands
{
public:
    Player4_Left_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_Player4_Left_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
