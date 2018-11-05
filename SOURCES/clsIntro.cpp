#include "clsIntro.h"

int clsIntro::init(clsScreen *s, clsMusic *m, clsEvent *e, clsTimer *t)
{
    error.set(music->load("MUSICA/PRESENTACION.mp3"));
    if(error.get()) return error.get();

    error.set(texto.loadFont("FONTS/FreeMono.ttf",30));
    if(error.get()) return error.get();

    texto.setFontColor(WHITE);

    screen = s;
    music = m;
    event = e;
    timer = t;

    setItems(14);
    char ruta[]= "IMAGES/MAGOINTRO/00.jpg";
    for(int d=0; d<2; d++)
    {
        ruta[17] = d + 48;
        for(int u=0; u<10; u++)
        {
            ruta[18] = u + 48;
            setI(d*10+u);

            error.set(load(ruta));
            if(error.get())
                return error.get();

            if(d*10+u == 13)
                break;
        }
    }
    setI(0);

    return error.get();
}

void clsIntro::animar()
{
    paste(screen->getPtr());
    if(getI() == 13)
        setI(0);
    else
        setI(getI() + 1);
}

int clsIntro::run()
{
    error.set(0);

//    music->play(-1);

    texto.write("Magic Software",400,200,screen->getPtr());
    texto.write("Presenta",100,400,screen->getPtr());
    texto.write("EL RPG!",200,500,screen->getPtr());

    while(true)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == SDL_QUIT || event->getKey() == KEY_ESCAPE)
                return -1;
            if(event->getKey() == KEY_ENTER)
                return 0;
        }
        timer->wait(150);
        animar();
        screen->refresh();
    }

    return 0;
}











