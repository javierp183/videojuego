#ifndef CLSJUEGO_H
#define CLSJUEGO_H

#include <clsError.h>
#include <clsEvent.h>
#include <clsMenuInicio.h>
#include <clsMusic.h>
#include <clsScreen.h>

class clsJuego
{
    private:
        clsError error;
        clsEvent *event;
        clsMenuInicio menuInicio;
        clsMusic *music;
        clsScreen *screen;

    public:
        int init(clsScreen*, clsEvent*, clsMusic*);
        int run();
};

#endif // CLSJUEGO_H
