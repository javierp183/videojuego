#ifndef CLSMENUINICIO_H
#define CLSMENUINICIO_H

#include <clsError.h>
#include <clsScreen.h>
#include <clsMusic.h>
#include <clsEvent.h>


class clsMenuInicio
{
    public:
        int init(clsScreen*, clsEvent*);
        int run();
        void cargarPartida(int);
        void nuevaPartida();
        void guardarPartida();
        void ayuda();
        void creditos();
        void salir();


    protected:
        clsScreen* screen;
        clsEvent* event;
        clsError error;
        clsMusic music;
};

#endif // CLSMENUINICIO_H
