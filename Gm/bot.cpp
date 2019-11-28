#include "mainwindow.h"
#include"ui_mainwindow.h"
#include <QMessageBox>
#include"mygraphicview.h"
#include"bot.h"




void bot::analis ()
{



    for (int i=minborderx;i<=maxborderx;i++)
    {
        for (int j=minbordery;j<=maxbordery;j++)
        {
            n=0;
            int rem=n;
            bool bb=false;
            bool border1=true;
            bool border2=true;
            bb=true;
            if (xod[i][j]==0)
            {
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                if (j>0)
                {
                    if (xod[i][j-1]==prov)
                    {
                        n=n+2;
                        bb=true;
                        if (j>1)
                        {
                            if (xod[i][j-2]==prov)
                            {
                                n=n+4;
                                if (j>2)
                                {
                                    if (xod[i][j-3]==prov)
                                    {
                                        n=n+6;
                                        if (j>3)
                                        {
                                            if (xod[i][j-4]==prov)
                                            {
                                                if (prov==2) n=123456;
                                                else n=12345;
                                            }
                                            else
                                                if (xod[i][j-4]==0)
                                                    if (prov==2) n=1234;
                                                    else n=123;
                                                else
                                                {
                                                    n=n-3;
                                                    border1=false;
                                                }
                                        }
                                        else border1=false;
                                    }
                                    else if (xod[i][j-3]>0) border1=false;
                                }
                                else border1=false;
                            }
                            else if (xod[i][j-2]>0) border1=false;
                        }
                        else border1=false;
                    }
                    else
                        if (xod[i][j-1]>0)
                        {
                            n=n+2;
                            bb=false;
                            border1=false;
                        }
                }
                else border1=false;
                if (j<18)
                {
                    if (xod[i][j+1]==prov)
                    {
                        if (n==123 || n==1234) bb=true;
                        n=n+2;
                        if (j<17)
                        {
                            if (xod[i][j+2]==prov)
                            {
                                n=n+4;
                                if (j<16)
                                {
                                    if (xod[i][j+3]==prov)
                                    {
                                        n=n+6;
                                        if (j<15)
                                        {
                                            if (xod[i][j+4]==prov)
                                            {
                                                if (prov==2) n=123456;
                                                else n=12345;
                                            }
                                            else
                                                if (xod[i][j+4]==0)
                                                    if (prov==2) n=1234;
                                                    else n=123;
                                                else
                                                {
                                                    n=n-3;
                                                    border2=false;
                                                }
                                        }
                                        else border2=false;
                                    }
                                    else if (xod[i][j+3]>0) border2=false;
                                }
                                else border2=false;
                            }
                            else if (xod[i][j+2]>0) border2=false;
                        }
                        else border2=false;
                    }
                else
                    if (xod[i][j+1]>0)
                    {
                        n=n+2;
                        bb=false;
                        border2=false;
                    }
                }
                else border2=false;
                if (n==rem+12 || n==rem+11 || n==rem+1235 || n==rem+124 || (n==rem+1236 && bb==true) || (n==rem+125 && bb==true))
                {
                    if (prov==2) n=123456;
                    else n=12345;
                }
                if (n==rem+8)
                {
                    if (prov==2) n=1234;
                    else n=123;
                }
                if (border1==false && border2==false && n<12345)
                    n=rem;
                else
                    if (border1==false || border2==false)
                        n=n-1;
                border1=true;
                border2=true;
                rem=n;
                bb=false;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




                    if (i<18 && j<18)
                    {
                        if (xod[i+1][j+1]==prov)
                        {
                            n=n+2;
                            bb=true;
                            if (i<17 && j<17)
                            {
                                if (xod[i+2][j+2]==prov)
                                {
                                    n=n+4;
                                    if (i<16 && j<16)
                                    {
                                        if (xod[i+3][j+3]==prov)
                                        {
                                            n=n+6;
                                            if (i<15 && j<15)
                                            {
                                                if (xod[i+4][j+4]==prov)
                                                {
                                                    if (prov==2) n=123456;
                                                    else n=12345;
                                                }
                                                else
                                                    if (xod[i+4][j+4]==0)
                                                        if (prov==2) n=1234;
                                                        else n=123;
                                                    else
                                                    {
                                                        n=n-3;
                                                        border1=false;
                                                    }
                                            }
                                            else border1=false;
                                        }
                                        else if (xod[i+3][j+3]>0) border1=false;
                                    }
                                    else border1=false;
                                }
                                else if (xod[i+2][j+2]>0) border1=false;
                            }
                            else border1=false;
                        }
                        else
                            if (xod[i+1][j+1]>0)
                            {
                                n=n+2;
                                bb=false;
                                border1=false;
                            }
                    }
                    else border1=false;
                    if (i>0 && j>0)
                    {
                        if (xod[i-1][j-1]==prov)
                        {
                            if (n==123 || n==1234) bb=true;
                            n=n+2;
                            if (i>1 && j>1)
                            {
                                if (xod[i-2][j-2]==prov)
                                {
                                    n=n+4;
                                    if (i>2 && j>2)
                                    {
                                        if (xod[i-3][j-3]==prov)
                                        {
                                            n=n+6;
                                            if (i>3 && j>3)
                                            {
                                                if (xod[i-4][j-4]==prov)
                                                {
                                                    if (prov==2) n=123456;
                                                    else n=12345;
                                                }
                                                else
                                                    if (xod[i-4][j-4]==0)
                                                        if (prov==2) n=1234;
                                                        else n=123;
                                                    else
                                                    {
                                                        n=n-3;
                                                        border2=false;
                                                    }
                                            }
                                            else border2=false;
                                        }
                                        else if (xod[i-3][j-3]>0) border2=false;
                                    }
                                    else border2=false;
                                }
                                else if (xod[i-2][j-2]>0) border2=false;
                            }
                            else border2=false;
                        }
                        else
                            if (xod[i-1][j-1]>0)
                            {
                                n=n+2;
                                bb=false;
                                border2=false;
                            }
                    }
                    else border2=false;
                    if (n==rem+12 || n==rem+11 || n==rem+1235 || n==rem+124 || (n==rem+1236 && bb==true) || (n==rem+125 && bb==true))
                    {
                        if (prov==2) n=123456;
                        else n=12345;
                    }
                    if (n==rem+8)
                    {
                        if (prov==2) n=1234;
                        else n=123;
                    }
                    if (border1==false && border2==false && n<12345)
                        n=rem;
                    else
                        if (border1==false || border2==false)
                            n=n-1;
                    border1=true;
                    border2=true;
                    rem=n;
                    bb=false;

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




                        if (i>0 && j<18)
                        {
                            if (xod[i-1][j+1]==prov)
                            {
                                n=n+2;
                                bb=true;
                                if (i>1 && j<17)
                                {
                                    if (xod[i-2][j+2]==prov)
                                    {
                                        n=n+4;
                                        if (i>2 && j<16)
                                        {
                                            if (xod[i-3][j+3]==prov)
                                            {
                                                n=n+6;
                                                if (i>3 && j<15)
                                                {
                                                    if (xod[i-4][j+4]==prov)
                                                    {
                                                        if (prov==2) n=123456;
                                                        else n=12345;
                                                    }
                                                    else
                                                        if (xod[i-4][j+4]==0)
                                                            if (prov==2) n=1234;
                                                            else n=123;
                                                        else
                                                        {
                                                            n=n-3;
                                                            border1=false;
                                                        }
                                                }
                                                else border1=false;
                                            }
                                            else if (xod[i-3][j+3]>0) border1=false;
                                        }
                                        else border1=false;
                                    }
                                    else if (xod[i-2][j+2]>0) border1=false;
                                }
                                else border1=false;
                            }
                            else
                                if (xod[i-1][j+1]>0)
                                {
                                    n=n+2;
                                    bb=false;
                                    border1=false;
                                }
                        }
                        else border1=false;
                        if (i<18 && j>0)
                        {
                            if (xod[i+1][j-1]==prov)
                            {
                                if (n==123 || n==1234) bb=true;
                                n=n+2;
                                if (i<17 && j>1)
                                {
                                    if (xod[i+2][j-2]==prov)
                                    {
                                        n=n+4;
                                        if (i<16 && j>2)
                                        {
                                            if (xod[i+3][j-3]==prov)
                                            {
                                                n=n+6;
                                                if (i<15 && j>3)
                                                {
                                                    if (xod[i+4][j-4]==prov)
                                                    {
                                                        if (prov==2) n=123456;
                                                        else n=12345;
                                                    }
                                                    else
                                                        if (xod[i+4][j-4]==0)
                                                            if (prov==2) n=1234;
                                                            else n=123;
                                                        else
                                                        {
                                                            n=n-3;
                                                            border2=false;
                                                        }
                                                }
                                                else border2=false;
                                            }
                                            else if (xod[i+3][j-3]>0) border2=false;
                                        }
                                        else border2=false;
                                    }
                                    else if (xod[i+2][j-2]>0) border2=false;
                                }
                                else border2=false;
                            }
                            else
                                if (xod[i+1][j-1]>0)
                                {
                                    n=n+2;
                                    bb=false;
                                    border2=false;
                                }
                        }
                        else border2=false;
                        if (n==rem+12 || n==rem+11 || n==rem+1235 || n==rem+124 || (n==rem+1236 && bb==true) || (n==rem+125 && bb==true))
                        {
                            if (prov==2) n=123456;
                            else n=12345;
                        }
                        if (n==rem+8)
                        {
                            if (prov==2) n=1234;
                            else n=123;
                        }
                        if (border1==false && border2==false && n<12345)
                            n=rem;
                        else
                            if (border1==false || border2==false)
                                n=n-1;
                        border1=true;
                        border2=true;
                        rem=n;
                        bb=false;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



                            if (i<18)
                            {
                                if (xod[i+1][j]==prov)
                                {
                                    n=n+2;
                                    bb=true;
                                    if (i<17)
                                    {
                                        if (xod[i+2][j]==prov)
                                        {
                                            n=n+4;
                                            if (i<16)
                                            {
                                                if (xod[i+3][j]==prov)
                                                {
                                                    n=n+6;
                                                    if (i<15)
                                                    {
                                                        if (xod[i+4][j]==prov)
                                                        {
                                                            if (prov==2) n=123456;
                                                            else n=12345;
                                                        }
                                                        else
                                                            if (xod[i+4][j]==0)
                                                                if (prov==2) n=1234;
                                                                else n=123;
                                                            else
                                                            {
                                                                n=n-3;
                                                                border1=false;
                                                            }
                                                    }
                                                    else border1=false;
                                                }
                                                else if (xod[i+3][j]>0) border1=false;
                                            }
                                            else border1=false;
                                        }
                                        else if (xod[i+2][j]>0) border1=false;
                                    }
                                    else border1=false;
                                }
                                else
                                    if (xod[i+1][j]>0)
                                    {
                                        n=n+2;
                                        bb=false;
                                        border1=false;
                                    }
                            }
                            else border1=false;
                            if (i>0)
                            {
                                if (xod[i-1][j]==prov)
                                {
                                    if (n==123 || n==1234) bb=true;
                                    n=n+2;
                                    if (i>1)
                                    {
                                        if (xod[i-2][j]==prov)
                                        {
                                            n=n+4;
                                            if (i>2)
                                            {
                                                if (xod[i-3][j]==prov)
                                                {
                                                    n=n+6;
                                                    if (i>3)
                                                    {
                                                        if (xod[i-4][j]==prov)
                                                        {
                                                            if (prov==2) n=123456;
                                                            else n=12345;
                                                        }
                                                        else
                                                            if (xod[i-4][j]==0)
                                                                if (prov==2) n=1234;
                                                                else n=123;
                                                            else
                                                            {
                                                                n=n-3;
                                                                border2=false;
                                                            }
                                                    }
                                                    else border2=false;
                                                }
                                                else if (xod[i-3][j]>0) border2=false;
                                            }
                                            else border2=false;
                                        }
                                        else if (xod[i-2][j]>0) border2=false;
                                    }
                                    else border2=false;
                                }
                                else
                                    if (xod[i-1][j]>0)
                                    {
                                        n=n+2;
                                        bb=false;
                                        border2=false;
                                    }
                            }
                            else border2=false;
                            if (n==rem+12 || n==rem+11 || n==rem+1235 || n==rem+124 || (n==rem+1236 && bb==true) || (n==rem+125 && bb==true))
                            {
                                if (prov==2) n=123456;
                                else n=12345;
                            }
                            if (n==rem+8)
                            {
                                if (prov==2) n=1234;
                                else n=123;
                            }
                            if (border1==false && border2==false && n<12345)
                                n=rem;
                            else
                                if (border1==false || border2==false)
                                    n=n-1;
                            border1=true;
                            border2=true;
                            rem=n;
                            bb=false;

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



                            if (max<n)
                            {
                                max=n;
                                comx=i;
                                comy=j;
                            }
                       }
                       if (n>=123456) break;
            }
            if (n>=123456) break;
      }
}




void bot::theend()
{
    int i,j;
    for (i=0;i<18;i++)
    {
        for (j=0;j<18;j++)
        {
            if (xod[i][j]==prov)
            {
                if (j>0) if (xod[i][j-1]==prov)
                {
                    if (j>1) if (xod[i][j-2]==prov)
                    {
                        if (j>2) if (xod[i][j-3]==prov)
                        {
                            if (j>3) if (xod[i][j-4]==prov)
                            {
                                game=false;
                                if (prov==1) text="ВЫ ВЫИГРАЛИ\nкликните по полю для начала новой игры";
                                else text="ВЫ ПРОИГРАЛИ\nкликните по полю для начала новой игры";

                            }
                        }
                    }
                }
                if (j<18) if (xod[i][j+1]==prov)
                {
                    if (j<17) if (xod[i][j+2]==prov)
                    {
                        if (j<16) if (xod[i][j+3]==prov)
                        {
                            if (j<15) if (xod[i][j+4]==prov)
                            {
                                game=false;
                                if (prov==1) text="ВЫ ВЫИГРАЛИ\nкликните по полю для начала новой игры";
                                else text="ВЫ ПРОИГРАЛИ\nкликните по полю для начала новой игры";
                            }
                        }
                    }
                }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                if (j>0) if (xod[i-1][j-1]==prov)
                {
                    if (j>1) if (xod[i-2][j-2]==prov)
                    {
                        if (j>2) if (xod[i-3][j-3]==prov)
                        {
                            if (j>3) if (xod[i-4][j-4]==prov)
                            {
                                game=false;
                                if (prov==1) text="ВЫ ВЫИГРАЛИ\nкликните по полю для начала новой игры";
                                else text="ВЫ ПРОИГРАЛИ\nкликните по полю для начала новой игры";
                            }
                        }
                    }
                }
                if (j<18) if (xod[i+1][j+1]==prov)
                {
                    if (j<17) if (xod[i+2][j+2]==prov)
                    {
                        if (j<16) if (xod[i+3][j+3]==prov)
                        {
                            if (j<15) if (xod[i+4][j+4]==prov)
                            {
                                game=false;
                                if (prov==1) text="ВЫ ВЫИГРАЛИ\nкликните по полю для начала новой игры";
                                else text="ВЫ ПРОИГРАЛИ\nкликните по полю для начала новой игры";
                            }
                        }
                    }
                }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

                if (j>0) if (xod[i-1][j+1]==prov)
                {
                    if (j>1) if (xod[i-2][j+2]==prov)
                    {
                        if (j>2) if (xod[i-3][j+3]==prov)
                        {
                            if (j>3) if (xod[i-4][j+4]==prov)
                            {
                                game=false;
                                if (prov==1) text="ВЫ ВЫИГРАЛИ\nкликните по полю для начала новой игры";
                                else text="ВЫ ПРОИГРАЛИ\nкликните по полю для начала новой игры";
                            }
                        }
                    }
                }
                if (j<18) if (xod[i+1][j-1]==prov)
                {
                    if (j<17) if (xod[i+2][j-2]==prov)
                    {
                        if (j<16) if (xod[i+3][j-3]==prov)
                        {
                            if (j<15) if (xod[i+4][j-4]==prov)
                            {
                                game=false;
                                if (prov==1) text="ВЫ ВЫИГРАЛИ\nкликните по полю для начала новой игры";
                                else text="ВЫ ПРОИГРАЛИ\nкликните по полю для начала новой игры";
                            }
                        }
                    }
                }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                if (j>0) if (xod[i-1][j]==prov)
                {
                    if (j>1) if (xod[i-2][j]==prov)
                    {
                        if (j>2) if (xod[i-3][j]==prov)
                        {
                            if (j>3) if (xod[i-4][j]==prov)
                            {
                                game=false;
                                if (prov==1) text="ВЫ ВЫИГРАЛИ\nкликните по полю для начала новой игры";
                                else text="ВЫ ПРОИГРАЛИ\nкликните по полю для начала новой игры";
                            }
                        }
                    }
                }
                if (j<18) if (xod[i+1][j]==prov)
                {
                    if (j<17) if (xod[i+2][j]==prov)
                    {
                        if (j<16) if (xod[i+3][j]==prov)
                        {
                            if (j<15) if (xod[i+4][j]==prov)
                            {
                                game=false;
                                if (prov==1) text="ВЫ ВЫИГРАЛИ\nкликните по полю для начала новой игры";
                                else text="ВЫ ПРОИГРАЛИ\nкликните по полю для начала новой игры";
                            }
                        }
                    }
                }




            }
            if (game==false) break;
        }
        if (game==false) break;
    }
}






void bot::algorithm ()
{
    prov=1;// проверяем первого (человек) игрока
    theend();// проверяем на конец игры
    if (game==true) // если игра продолжается
    {
        prov=2;// проверяем второго (комп) игрока
        max=0; // устанавливаем первоночальное максимальное занчение кол-ва очков хода
        analis(); // получаем новое максимальное занчение кол-ва очков хода и его координаты
        prov=1;// проверяем первого (человек) игрока
        analis();// получаем новое максимальное занчение кол-ва очков хода и его координаты
        /*if (max==0)
        {
            do
            {
                comx=rand()%6+7;
                comy=rand()%6+7;
            }
            while (xod[comx][comy]==0 && comx>=0 && comy>=0 && comx<=18 && comy<=18);
        }*/
        xod[comx][comy]=2;//заносим ход компа в матрицу ходов
        prov=2;// проверяем второго (комп) игрока
        theend();// проверяем на конец игры
    }
}

int bot::take(int i, int j)
{
    return xod[i][j];
}

void bot::give(int i, int j)
{
    if (i>=0 && j>=0 && i<=18 && j<=18) xod[i][j]=1;
}

/*void bot::newgame(int size)
{
    for (int i=0;i<19;i++)
    {
        for (int j=0;j<19;j++)
        {
            xod[i][j]=0;
        }
    }
    n=max=0;
    comx=0;
    comy=0;
    game=true;
    text="  ";
    newsize(size-1);
}*/

void bot::newgame()
{
    for (int i=0;i<19;i++)
    {
        for (int j=0;j<19;j++)
        {
            xod[i][j]=0;
        }
    }
    n=max=0;
    comx=0;
    comy=0;
    game=true;
    text="  ";
}

bool bot::isgame()
{
    return game;
}

void bot::newsize(int a)
{
    if (a>0 && a<=19) tile_x=tile_y=a;
}

int bot::takesize()
{
    if (tile_x==tile_y) return tile_x;
    return 0;
}

QString bot::letter()
{
    return text;
}

void bot::changeborders(int x, int y)
{
    if (x==18) maxborderx=18;
    if (x==0) minborderx=0;
    if (y==18) maxbordery=18;
    if (y==0) minbordery=0;
    if (x>=maxborderx-1 && maxborderx<18 && x<18) maxborderx=x+1;
    if (x<=minborderx+1 && minborderx>0 && x>0) minborderx=x-1;
    if (y>=maxbordery-1 && maxbordery<18 && y<18) maxbordery=y+1;
    if (y<=minbordery+1 && minbordery>0 && y>0) minbordery=y-1;
}

