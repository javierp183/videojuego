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

    return error.get();
}

int clsMotor::run()
{
    error.set(0);
    screen.clean(WHITE);
    screen.refresh();
    bool salir = false;
    while(!salir)
    {
        if(event.wasEvent())
        {
            switch(event.getEventType())
            {
                case KEY_PRESSED:
                {
                    error.set(keyPressed());
                    if(error.get()) return error.get();

                }break;
                case KEY_FREE:
                {
                    error.set(keyReleased());
                    if(error.get()) return error.get();

                }break;
                case MOUSE_DOWN:
                {
                    error.set(mouseDown());
                    if(error.get()) return error.get();

                }break;
                case MOUSE_UP:
                {
                    error.set(mouseUp());
                    if(error.get()) return error.get();

                }break;
                case MOUSE_MOTION:
                {
                    error.set(mouseMotion());
                    if(error.get()) return error.get();

                }break;
            }//Fin switch
        }//Fin if
    }//Fin while

    return error.get();
}

int clsMotor::keyPressed()
{
    error.set(0);

    switch(event.getKey())
    {

    }//Fin switch

    return error.get();
}

int clsMotor::keyReleased()
{
    error.set(0);

    switch(event.getKey())
    {

    }//Fin switch

    return error.get();
}

int clsMotor::mouseDown()
{
    error.set(0);

    switch(event.getMouseButton())
    {
        case MOUSE_LEFT_BUTTON:
        {

        }break;
        case MOUSE_MIDDLE_BUTTON:
        {

        }break;
        case MOUSE_RIGHT_BUTTON:
        {

        }break;
    }

    return error.get();
}

int clsMotor::mouseUp()
{
    error.set(0);

    switch(event.getMouseButton())
    {
        case MOUSE_LEFT_BUTTON:
        {

        }break;
        case MOUSE_MIDDLE_BUTTON:
        {

        }break;
        case MOUSE_RIGHT_BUTTON:
        {

        }break;
    }

    return error.get();
}

int clsMotor::mouseMotion()
{
    error.set(0);
    int x = event.getCursorX();
    int y = event.getCursorY();

    return error.get();
}
