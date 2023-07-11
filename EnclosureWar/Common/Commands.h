#ifndef COMMANDS_H
#define COMMANDS_H

#include <QSharedPointer>

class Commands
{
public:
    Commands() {}
public:
    virtual void exec() = 0;
};

#endif // COMMANDS_H
