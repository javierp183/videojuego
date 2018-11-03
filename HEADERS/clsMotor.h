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
#include <clsJuego.h>

class clsMotor
{
    private:
        clsAudio audio;
        clsError error;
        clsEvent event;
        clsIntro intro;
        clsJuego juego;
        clsMode mode;
        clsMusic music;
        clsScreen screen;
        clsText texto;
        clsTimer timer;

    public:
        int init();
        int run();
};

#endif // CLSMOTOR_H
