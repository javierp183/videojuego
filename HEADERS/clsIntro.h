#ifndef CLSINTRO_H
#define CLSINTRO_H

#include <clsSprite.h>
#include <clsScreen.h>
#include <clsMusic.h>
#include <clsEvent.h>
#include <clsText.h>
#include <clsTimer.h>


class clsIntro : public clsSprite
{
    public:
       void inherit(){};
       int init(clsScreen *s,clsMusic *m,clsEvent *e,clsTimer *t);
       void animar();
       int run();
    private:
        clsScreen *screen;
        clsMusic *music;
        clsEvent *event;
        clsTimer *timer;
        clsText texto;


};

#endif // CLSINTRO_H
