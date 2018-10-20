#include "clsMotor.h"
#include <clsScreen.h>

int clsMotor::init()
{
    error.set(0);

    error.set(mode.init(DEFAULT));
    if(error.get()) return error.get();

    error.set(screen.init(mode.getScrWidth(),
                          mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          RESIZABLE));
    if(error.get()) return error.get();

    salir = false;

//Imagen de introduccion del Video Juego RPG con patas.
    error.set(intro.init(&screen));
    if(error.get())
    {

            error.show(true);
            return error.get();

    }

    return error.get();
}

int clsMotor::run()
{
    error.set(0);
    intro.paste(screen.getPtr());
    screen.refresh();

    while(!salir)
    {
        if(event.wasEvent())
        {
            switch(event.getEventType())
            {
                case KEY_PRESSED:
                {
                    if(event.getKey() == KEY_ESCAPE)
                    {
                    salir = true;
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
