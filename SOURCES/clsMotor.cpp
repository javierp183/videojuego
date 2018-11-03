#include "clsMotor.h"

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

//Imagen de introduccion del Video Juego RPG.
    error.set(intro.init(&screen,&music,&event));
    if(error.get())
    {
            error.show(true);
            return error.get();
    }
    error.set(texto.init());
    if(error.get())
    {
            error.show(true);
            return error.get();
    }
    error.set(audio.init());
    if(error.get())
    {
            error.show(true);
            return error.get();
    }





    return error.get();
}

int clsMotor::run()
{
    error.set(intro.run());
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

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
                    music.stop();
                    salir = true;
                    }else if(event.getKey() == KEY_ENTER)
                    {
                        music.stop();
                    }
                }break;

                case SDL_QUIT:
                {
                    return 0;
                }break;
            }//Fin switch/
        }//Fin if
    }//Fin while

    return error.get();
}
