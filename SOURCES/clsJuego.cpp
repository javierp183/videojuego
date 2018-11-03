#include "clsJuego.h"

int clsJuego::init(clsScreen* scr, clsEvent* ev, clsMusic* mus)
{
    error.set(0);

    screen = scr;
    event = ev;
    music = mus;

    return error.get();
}

int clsJuego::run()
{
    error.set(0);

    while(true)
    {
        if(event->wasEvent())
        {
            switch(event->getEventType())
            {
                case KEY_PRESSED:
                {
                    if(event->getKey() == KEY_ESCAPE)
                    {
                        return 0;
                    }
                }break;

                case SDL_QUIT:
                {
                    return 0;
                }break;
            }//Fin switch
        }//Fin if
    }//Fin while

    return error.get();
}
