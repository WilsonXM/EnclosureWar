#ifndef PLAYER3_RIGHT_COMMAND_H
#define PLAYER3_RIGHT_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class Player3_Right_Command :public Commands
{
public:
    Player3_Right_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_Player3_Right_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
