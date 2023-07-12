#ifndef BUILDGAME3P_COMMAND_H
#define BUILDGAME3P_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class BuildGame3P_Command :public Commands
{
public:
    BuildGame3P_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_BuildGame3P_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
