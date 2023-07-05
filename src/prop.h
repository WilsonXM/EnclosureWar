#ifndef _PROP_H_
#define _PROP_H_

enum class PropType
{
    NONE = 0,
    SPEEDUP,
    OCCUPATION
};

class Prop
{
public:
    Prop() : proptype_(PropType::NONE){};
    Prop(PropType proptype) : proptype_(proptype){};
    ~Prop() {}

public:
    PropType GetPropType() { return proptype_; }

public:
    void SetPropType(PropType proptype) { proptype_ = proptype; };
    void Init() { proptype_ = PropType::NONE; }

private:
    PropType proptype_;
};

#endif