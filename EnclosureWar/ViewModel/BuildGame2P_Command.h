#ifndef BUILDGAME2P_COMMAND_H
#define BUILDGAME2P_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class BuildGame2P_Command :public Commands
{
public:
    BuildGame2P_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_BuildGame2P_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
