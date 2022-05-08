#include "graphics.hpp"
#include "widget.h"
#include "nygom.h"
#include "iostream"

using namespace genv;

nygomb::nygomb(int x,int y,int sx, int sy):widget(x,y,sx,sy)
{
    katt=false;
}

void nygomb::esemeny(genv::event ev)
{
    int ex=ev.pos_x;
    int ey=ev.pos_y;

    if(actual(ex,ey)&&ev.type==ev_mouse&&ev.button==btn_left)
    {
        katt=true;


    }

}

bool nygomb::actual(int ex, int ey)
{
return ex>=x && ex<=x+sx && ey>y &&ey<y+sy;
}

void nygomb::rajz()
{
    gout<<move_to(x,y)<<color(150,150,150)<<box(sx,sy);
    gout<<move_to(x+2,y+2)<<color(200,200,200)<<box(sx-4,sy-4);
    gout<<move_to(x+sx/2-5,y+sy/2+5)<<color(0,0,0)<<text(s);
    if(katt)
    {
        gout<<move_to(x,y)<<color(200,0,0)<<box(sx,sy);
        gout<<move_to(x+2,y+2)<<color(200,200,200)<<box(sx-4,sy-4);
        gout<<move_to(x+sx/2-5,y+sy/2+5)<<color(0,0,0)<<text(s);
        katt=false;
    }
}

void nygomb::setszoveg(std::string a)
{
s=a;
}
std::string nygomb::gets()
{
    return s;
}
