#ifndef CLSPERSONAJE_H
#define CLSPERSONAJE_H

#include <clsSprite.h>


class clsPersonaje : public clsSprite
{

    public:
    void inherit();
    int init(clsScreen *);
    void animar();
    void caminarX(int x);
    void caminarY(int y);

    protected:

    private:
            clsScreen *screen;
    tDireccion direccion;
    int velX;
    int velY;
};

#endif // CLSPERSONAJE_H
