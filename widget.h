#ifndef AS_H_INCLUDED
#define AS_H_INCLUDED

#include "graphics.hpp"
class widget
{
protected:
    int x,y,sx,sy;
public:
    widget(int x, int y, int sx, int sy);
    virtual void rajz()=0;
    virtual void esemeny(genv::event)=0;
    virtual bool actual(int ex, int ey);
};

#endif // AS_H_INCLUDED
