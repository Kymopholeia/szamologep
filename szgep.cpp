#include "graphics.hpp"
#include "kij.h"
#include "nygom.h"
#include "szgep.h"
#include <iostream>
#include <sstream>

using namespace genv;

szgep::szgep(int _c,int _v):c(_c),v(_v)
{
    int u=sc/3-20;
    int l=(sv-35)/4;

nygomb *n1=new nygomb(c,v+35,u,l);
n1->setszoveg("1");
nygomb *n2=new nygomb(c+u,v+35,u,l);
n2->setszoveg("2");
nygomb *n3=new nygomb(c+u*2,v+35,u,l);
n3->setszoveg("3");
nygomb *n4=new nygomb(c,v+35+l,u,l);
n4->setszoveg("4");
nygomb *n5=new nygomb(c+u,v+35+l,u,l);
n5->setszoveg("5");
nygomb *n6=new nygomb(c+u*2,v+35+l,u,l);
n6->setszoveg("6");
nygomb *n7=new nygomb(c,v+35+l*2,u,l);
n7->setszoveg("7");
nygomb *n8=new nygomb(c+u,v+35+l*2,u,l);
n8->setszoveg("8");
nygomb *n9=new nygomb(c+u*2,v+35+l*2,u,l);
n9->setszoveg("9");
nygomb *n0=new nygomb(c+u,v+35+l*3,u,l);
n0->setszoveg("0");
//w.push_back(k1);
w.push_back(n1);
w.push_back(n2);
w.push_back(n3);
w.push_back(n4);
w.push_back(n5);
w.push_back(n6);
w.push_back(n7);
w.push_back(n8);
w.push_back(n9);
w.push_back(n0);
nygomb *nc=new nygomb(c+u*2,v+35+l*3,u,l);
nc->setszoveg("C");
nygomb *np=new nygomb(c+3*u,v+35,sc-3*u,l);
np->setszoveg("+");
nygomb *nm=new nygomb(c+3*u,v+35+l,sc-3*u,l);
nm->setszoveg("-");
nygomb *ne=new nygomb(c+3*u,v+35+l*2,sc-3*u,l*2);
ne->setszoveg("=");
w.push_back(nc);
w.push_back(np);
w.push_back(nm);
w.push_back(ne);

//w.push_back(k1);
}

void szgep::muvelet()
{

}

void szgep::rajzol()
{
gout<<move_to(c,v)<<color(200,200,200)<<box(sc,sv);


}

void szgep::event_loop()
{
    kijelzo *k1=new kijelzo(c,v,sc,35);
    event ev;
    int focus=-1;
    std::stringstream ss(int);
    std::vector<int>f;
    std::string r;

    int a;
    int b;
    while(gin>>ev&&ev.keycode!=key_escape&& ev.keycode!=key_escape)
	{
	    k1->rajz();
	        for(size_t i=0;i<w.size();i++)
        {
            w[i]->rajz();

        }
		if(ev.type==ev_mouse&&ev.button==btn_left)
			for(size_t i=0;i<w.size();i++)
				if(w[i]->actual(ev.pos_x,ev.pos_y)){
                        //std::cout<<i<<' '<<ev.pos_x<<' '<<ev.pos_y<<std::endl;
                        //std::cout<<<<std::endl;
					focus=i;
int m;

					 if(w[i]->gets()=="-" )
                     {
                         r=k1->getszam();
                        a=stoi(r);
                        f.push_back(a);
                        m=1;
                        std::cout<<m<<std::endl;
                     }
                      if(w[i]->gets()=="+" )
                     {
                        r=k1->getszam();
                        a=stoi(r);
                        f.push_back(a);
                        m=2;
                        //std::cout<<m<<std::endl;
                     }
                      if(w[i]->gets()=="=" &&k1->getszam()!="")
                     {
                         r=k1->getszam();
                        a=stoi(r);
                        f.push_back(a);
                        if(m==2){b=f[0]+f[1];}
                        if(m==1){b=f[0]-f[1];}

                         //std::cout<<c<<' '<<d<<' '<<b<<std::endl;
                        // std::cout<<m<<std::endl;
f.clear();
                        k1->setszoveg("clear");

                     }
                     if(w[i]->gets()=="C")
                     {
                         k1->setszoveg("clear");
                         f.clear();
                     }
                        r=std::to_string(b);
                     if(i<w.size()-1)k1->setszoveg(w[i]->gets());



                     if(i==w.size()-1)k1->setszoveg(r);



//std::cout<<w[i]->gets()<<std::endl;
					}

		if(focus!=-1){
            w[focus]->esemeny(ev);
            w[focus]->rajz();
		}

		gout<<refresh;
	}

}
