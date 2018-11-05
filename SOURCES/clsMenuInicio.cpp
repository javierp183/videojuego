#include "clsMenuInicio.h"

int clsMenuInicio::init(clsScreen* scr, clsEvent* ev, clsMusic* mus)
{
    error.set(0);

    setItems(1);
    setI(0);
    error.set(load("IMAGES/Menu.png"));
    if(error.get()) return error.get();

    music->close();
    error.set(music->load("MUSICA/DRAMATISMO.mp3"));
    if(error.get()) return error.get();

    screen = scr;
    event = ev;
    music = mus;

    setX(screen->getWidth()/2 - getWidth()/2);
    setY(screen->getHeight()/2 - getHeight()/2);

    return error.get();
}

int clsMenuInicio::run()
{
    error.set(0);
//    music->play(-1);
    screen->clean(BLACK);

    while(true)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == SDL_QUIT)
                return -1;
            if(event->getKey() == KEY_ESCAPE)
                return 0;
        }
        paste(screen->getPtr());
        screen->refresh();
    }

    return error.get();
}
