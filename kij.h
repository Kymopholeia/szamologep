#ifndef KIJ_H_INCLUDED
#define KIJ_H_INCLUDED
#include "widget.h"
#include <vector>
class kijelzo: public widget
{
protected:
   std::vector<std::string> vs;
   std::string s;
public:
    kijelzo(int x, int y, int sx, int sy);
    virtual void rajz(int q, int w,int sq, int sw);
    virtual void rajz();
    virtual void esemeny(genv::event);
    virtual bool actual(int ex, int ey);
    virtual void setszoveg(std::string a);
    std::string getszam();
};

#endif // KIJ_H_INCLUDED
