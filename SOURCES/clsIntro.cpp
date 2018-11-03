#include "clsIntro.h"

int clsIntro::init(clsScreen *s,clsMusic *m,clsEvent *e)
{
    screen = s;
    music = m;
    event = e;

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


void clsIntro::animar()
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

int clsIntro::run()
{
    error.set(0);
    music->load("MUSICA/PRESENTACION.mp3");
    music->play(1);

    screen->refresh();
    texto.loadFont("FONTS/FreeMono.ttf",30);
    texto.setFontColor(WHITE);
    texto.write("Magic Software",400,200,screen->getPtr());
    texto.write("Presenta",100,400,screen->getPtr());
    texto.write("EL RPG!",200,500,screen->getPtr());
    screen->refresh();

    while(true)
    {
        //timer.wait(150);
       clsIntro::animar();
       screen->refresh();

    }


    return 0;
}











