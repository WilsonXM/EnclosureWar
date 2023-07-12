#ifndef PLAYER3_LEFT_COMMAND_H
#define PLAYER3_LEFT_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class Player3_Left_Command :public Commands
{
public:
    Player3_Left_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_Player3_Left_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
