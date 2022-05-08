#ifndef NYGOM_H_INCLUDED
#define NYGOM_H_INCLUDED

#include "widget.h"

class nygomb: public widget
{
protected:
    bool katt;

public:
    std::string s;
    nygomb(int x, int y, int sx, int sy);
    virtual void rajz();
    virtual void esemeny(genv::event);
    virtual bool actual(int ex, int ey);
    virtual void setszoveg(std::string a);
    std::string gets();
};

#endif // NYGOM_H_INCLUDED
