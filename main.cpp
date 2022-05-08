#include "graphics.hpp"
#include "widget.h"
#include "nygom.h"
#include "kij.h"
#include "szgep.h"
#include <vector>
using namespace genv;

const int XX=800;
const int YY=800;



int main()
{
    gout.open(XX,YY);
    event ev;

szgep * sz1=new szgep(100,50);
sz1->rajzol();
sz1->event_loop();
    gout<<refresh;
    return 0;
}
