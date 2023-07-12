#ifndef BUILDGAME4P_COMMAND_H
#define BUILDGAME4P_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class BuildGame4P_Command :public Commands
{
public:
    BuildGame4P_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_BuildGame4P_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
