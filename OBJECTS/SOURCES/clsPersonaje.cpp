#include "clsPersonaje.h"


    int clsPersonaje::init(clsScreen *s)
    {
        screen = s;
        setItems(1);
        setI(0);
        error.set(load("IMAGES/PERSONAJEIMG/24.gif"));
        if(error.get())
        {
            error.show(true);
            return error.get();
        }
        velX = 0;
        velY = 0;
        return error.get();
    }

        void clsPersonaje::animar()
    {
        setX(getX() + velX);
        setY(getY() + velY);
        paste(screen->getPtr());
    }

        void clsPersonaje::caminarX(int x)
    {
        velX = velX+x;
    }

        void clsPersonaje::caminarY(int y)
    {
        velY = velY+y;
    }
