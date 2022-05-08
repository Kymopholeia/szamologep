#include "widget.h"

widget::widget(int _x, int _y,int _sx, int _sy): x(_x), y(_y), sx(_sx), sy(_sy)
{

}

bool widget::actual(int ex, int ey)
{
 return ex>=x && ex<=x+sx && ey>y &&ey<y+sy;
}
