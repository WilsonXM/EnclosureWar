#ifndef BUILDGAME_COMMAND_H
#define BUILDGAME_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class BuildGame_Command :public Commands
{
public:
    BuildGame_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_BuildGame_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
