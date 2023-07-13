#ifndef BLOCKCHANGE_COMMAND_H
#define BLOCKCHANGE_COMMAND_H

#include "./Common/Commands.h"

template <class ViewModel>
class BlockChange_Command :public Commands
{
public:
    BlockChange_Command(QSharedPointer<ViewModel> vm) { m_VM = vm; }

    void exec() override { m_VM->Exec_BlockChange_Command(); }

private:
    QSharedPointer<ViewModel> m_VM;
};

#endif
