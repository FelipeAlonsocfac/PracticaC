#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>

using namespace std;

class Complejo
{
private:
    float _real, _imag;
public:
    Complejo(); // contructor por omision
    Complejo(float r,float i ); //Constructor con parametros
 // FALTA LA VIRGULILLA   Complejo();  // Destructor
    Complejo operator +(Complejo a);
    Complejo operator -(Complejo a);
    Complejo operator <(Complejo a);
    ostream operator <<(ostream stream);
    bool operator ==(Complejo a);
};

#endif // COMPLEJO_H
