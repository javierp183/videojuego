#ifndef CLSMOTOR_H
#define CLSMOTOR_H

#include <clsEvent.h>
#include <clsError.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <clsMotor.h>
#include <clsIntro.h>
#include <clsTimer.h>

class clsMotor
{
    private:
        clsIntro intro;
        clsTimer timer;

    protected:
        clsEvent event;
        clsError error;
        clsMode mode;
        clsScreen screen;
        bool salir;

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
