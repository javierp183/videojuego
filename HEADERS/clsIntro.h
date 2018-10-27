#ifndef CLSINTRO_H
#define CLSINTRO_H

#include <clsSprite.h>
#include <clsScreen.h>


class clsIntro : public clsSprite
{
    public:
       void inherit(){};
       int init(clsScreen *s);
       int animar();
    private:
        clsScreen *screen;
};

#endif // CLSINTRO_H
