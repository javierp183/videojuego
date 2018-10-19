#include "clsIntro.h"


int clsIntro::init(clsScreen *s)
{

    screen = s;
    setItems(1);
    setI(0);
    error.set(load("IMG/Intro.png"));
    if(error.get())
    {

        error.show(true);
        return error.get();

    }

    return error.get();

}
