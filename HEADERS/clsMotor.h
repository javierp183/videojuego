#ifndef CLSMOTOR_H
#define CLSMOTOR_H

#include <clsEvent.h>
#include <clsError.h>
#include <clsMode.h>
#include <clsScreen.h>

class clsMotor
{
    protected:
        clsEvent event;
        clsError error;
        clsMode mode;
        clsScreen screen;

    public:
        int init();
        int run();
        int keyPressed();
        int keyReleased();
        int mouseDown();
        int mouseUp();
        int mouseMotion();
};

#endif // CLSMOTOR_H
