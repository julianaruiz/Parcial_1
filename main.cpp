#include <iostream>
#include <math.h>
#define r_des_D 0.025
#define r_des_O 0.05
#define pi 3.141
#define g 9,81

using namespace std;

int main()
{
    float v_o,angu_o,h1,h2,d, x(t), y(t), a, b, c;
    cout << "Sistema de control de disparo defensivo" << endl;
    cout << endl;
    cout << "Ingrese la velocidad inicial del cañon enemigo: ";
    cin >> v_o;
    cout << "Ingrese el angulo del cañon enemigo: ";
    cin >> angu_o;
    cout << "Ingrese la altura del cañon ofensivo: ";
    cin >> h1;
    cout << "Ingrese la altura del cañon defesnivo: ";
    cin >> h2;
    cout << "Ingrese la distancia entre los dos cañones: ";
    cin >> d;

    a=g/2;
    b=v_o*sin(sin(angu_o*pi/180));
    c=h1;
    x(t)=v_o*(cos(angu_o*pi/180));


    return 0;
}
