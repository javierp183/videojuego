#include "clsJuego.h"

int clsJuego::init(clsScreen* scr, clsEvent* ev, clsMusic* mus)
{
    error.set(0);

    error.set(menuInicio.init(scr, ev, mus));
    if(error.get()) return error.get();

    screen = scr;
    event = ev;
    music = mus;

    return error.get();
}

int clsJuego::run()
{
    error.set(0);

    error.set(menuInicio.run());
    if(error.get()) return error.get();

    return error.get();
}
