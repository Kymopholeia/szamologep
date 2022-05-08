#include "graphics.hpp"
#include "kij.h"
#include <vector>

using namespace genv;

kijelzo::kijelzo(int x, int y, int sx, int sy): widget(x,y,sx,sy)
{

}

void kijelzo::esemeny(genv::event ev)
{

}

bool kijelzo::actual(int ex, int ey)
{

}

void kijelzo::rajz()
{
    if(sy<30)sy=35;
    gout<<move_to(x,y)<<color(100,100,100)<<box(sx,sy);
    gout<<move_to(x+3,y+3)<<color(255,255,255)<<box(sx-6,sy-6);
    gout<<move_to(x+7,y+sy/2+5)<<color(0,0,0)<<text(s);
}

void kijelzo::rajz(int q, int w,int sq, int sw)
{
    if(sw<30)sw=35;
    gout<<move_to(q,w)<<color(100,100,100)<<box(sq,sw);
    gout<<move_to(q+3,w+3)<<color(255,255,255)<<box(sq-6,sw-6);
    gout<<move_to(q+7,y+sw/2+5)<<color(0,0,0)<<text(s);
}

void kijelzo::setszoveg(std::string a)
{
    if(a!="+"&&a!="-"&&a!="="&&a!="clear"&&a!="C")
    {
        s=s+a;
        //vs.pop_back();
        vs.push_back(s);
    }
    else{vs.clear();
            s=" ";
            vs.push_back(s);
    }
    if(a=="clear"||a=="C")
    {
        vs.clear();
//            s=" ";
//            vs.push_back(s);
    }
}
std::string kijelzo::getszam()
{
    return s;
}
