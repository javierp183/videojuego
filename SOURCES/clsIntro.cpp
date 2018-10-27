#include "clsIntro.h"
//int clsIntro::init(clsScreen *s)
//{
//   screen = s;
//   setItems(1);
//   setI(0);
//   error.set(load("IMG/INTRO/00.jpg"));
//   if(error.get())
//   {
//       error.show(true);
//       return error.get();
//   }
//   return error.get();
//}

int clsIntro::init(clsScreen *s)
{
    screen = s;
    setItems(14);
    char ruta [] = "IMAGES/MAGOINTRO/00.jpg";
    for(int d=0; d<1; d++)
    {
        ruta[17] = d + 48;
        for(int u=0; u<10; u++)
        {
            ruta[18] = u +48;
            setI(d*10+u);
            cout<<ruta<<endl;
            error.set(load(ruta));
            if(d*10+u == 14)
            {
                break;
            }
        }

    }
    return error.get();

}


int clsIntro::animar()
{
    paste(screen->getPtr());
    if(getI() == 9)
    {
        setI(0);
    }
    else
    {
        setI(getI() + 1);
    }

}













