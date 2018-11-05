#ifndef CLSMENUINICIO_H
#define CLSMENUINICIO_H

#include <clsSprite.h>
#include <clsError.h>
#include <clsScreen.h>
#include <clsMusic.h>
#include <clsEvent.h>


class clsMenuInicio : public clsSprite
{
    public:
        void inherit(){}
        int init(clsScreen*, clsEvent*, clsMusic*);
        int run();
        void nuevaPartida();
        void cargarPartida(int);
        void ayuda();
        void creditos();
        void salir();


    protected:
        clsScreen *screen;
        clsEvent *event;
        clsError error;
        clsMusic *music;
};

#endif // CLSMENUINICIO_H
