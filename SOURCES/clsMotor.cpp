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
    music.load("MUSICA/PRESENTACION.mp3");
    music.play(1);

    screen.refresh();
    texto.loadFont("FONTS/FreeMono.ttf",30);
    texto.setFontColor(WHITE);
    texto.write("Magic Software",400,200,screen.getPtr());
    texto.write("Presenta",100,400,screen.getPtr());
    texto.write("EL RPG!",200,500,screen.getPtr());
    screen.refresh();



    while(!salir)
    {
        intro.animar();

        screen.refresh();

        if(event.wasEvent())
        {
            switch(event.getEventType())
            {
                case KEY_PRESSED:
                {
                    switch(event.getKey())
                    {
                    case KEY_ENTER:
                        {
                            if( music.getStatus() == 0 )
                                music.play(1);
                            else
                                music.stop();
                        }break;
                    case KEY_SPACE:
                        {
                            if( music.getStatus() == 1 )
                                music.pause();
                            else
                                music.resume();
                        }break;
                    case KEY_ESCAPE:
                        {
                            salir = true;
                        }break;
                    }
                }break;

                case SDL_QUIT:
                {
                    return 0;
                }break;
            }//Fin switch
        }//Fin if

        timer.wait(150);

    }//Fin while

    return error.get();
}


//int clsMotor::keyPressed()
//{
  //  switch(event.getKey())
   // {
    //case KEY_UP:
      //  {
        //    heroe.caminarY(-1);
        //}break;
    //case KEY_DOWN:
      //  {
        //    heroe.caminarY(1);
        //}break;
    //case KEY_LEFT:
      //  {
        //    heroe.caminarX(-1);
        //}break;
    //case KEY_RIGHT:
      //  {
        //    heroe.caminarX(1);
        //}break;
   // }
   // return 0;
//}
