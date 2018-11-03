#ifndef CLSMOTOR_H
#define CLSMOTOR_H

#include <clsEvent.h>
#include <clsError.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <clsMotor.h>
#include <clsIntro.h>
#include <clsTimer.h>
#include <clsText.h>
#include <clsMusic.h>
#include <clsAudio.h>
#include <clsSoundEffect.h>
#include <clsPersonaje.h>


class clsMotor
{
    private:
        clsIntro intro;
        clsTimer timer;
        clsText texto;
        clsMusic music;
        clsAudio audio;


    protected:
        clsEvent event;
        clsError error;
        clsMode mode;
        clsScreen screen;
        bool salir;

    public:
        int init();
        int run();
};

#endif // CLSMOTOR_H
