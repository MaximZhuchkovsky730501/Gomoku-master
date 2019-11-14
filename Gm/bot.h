#ifndef BOT_H
#define BOT_H
#include <iostream>
#include <math.h>
#include <QString>
//#include <admin.h>



class bot
{
public:
    bot()
    {
        xod[0][0]={0};
        tile_y=tile_x=18;
        minborderx=18;
        maxborderx=0;
        minbordery=18;
        maxbordery=0;
        text="  ";
        game=true;
    }

    void analis ();
    void theend();
    void algorithm ();
    int take (int i, int j);
    void give(int i, int j);
    void newgame();
    //void newgame(int size);
    bool isgame();
    void newsize(int a);
    int takesize();
    QString letter();
    void changeborders(int x, int y);

private:

    int xod[19][19];
    int n;
    int max;
    int prov;
    int tile_x;
    int tile_y;
    int comx;
    int comy;
    int minborderx;
    int maxborderx;
    int minbordery;
    int maxbordery;
    QString text;
    bool game;
};

static bot master;

#endif // BOT_H
