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

//Imagen de introduccion del Video Juego RPG con patas.
    error.set(intro.init(&screen));
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

    error.set(0);

    music.loadMusic("MUSICA/PRESENTACION.mp3");
    music.playMusic(1);

    intro.paste(screen.getPtr());
    screen.refresh();
    texto.loadFont("FONTS/FreeMono.ttf",30);
    texto.setFontColor(WHITE);
    texto.write("Magic Software",150,500,screen.getPtr());
    texto.write("Presenta",170,550,screen.getPtr());
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
                    }else if(event.getKey() == KEY_ENTER)
                    {
                        music.stopMusic();
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
