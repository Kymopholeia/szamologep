#ifndef SZGEP_H_INCLUDED
#define SZGEP_H_INCLUDED

#include "widget.h"
#include<vector>
class szgep
{
protected:
   int c,v;
   int sc=200;
   int sv=200;
   std::vector<nygomb*> w;
public:
    szgep(int c,int v);
    void muvelet();
    void rajzol();
    void event_loop();

};

#endif // SZGEP_H_INCLUDED
