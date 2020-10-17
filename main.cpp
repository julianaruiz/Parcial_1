#include <iostream>
#include <math.h>
#define r_des_D 0.025
#define r_des_O 0.05
#define pi 3.141
#define g 9,81
#define t_0 2.5

using namespace std;

int main()
{
    float v_o, angu_o, h1, , d, x_max, y_max, a, b, c, t1, t2, t, x(t_0), y(t_0), y_max_D;
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
    cout << "Ingrese la distancia desde el cañón ofesnivo hasta el defensivo: ";
    cin >> d;

    a=g/2; //parte de grado 2 de y(t).
    b=v_o*sin(sin(angu_o*pi/180)); //parte de grado 1 de y(t).
    c=h1; //parte constante de y(t).
    t1=(-b+sqrt((pow(b,2))-4*a*c))/(2*a); //función cuadrática con raíz positiva.
    t2=(-b-sqrt((pow(b,2))-4*a*c))/(2*a); //función cuadrática con raíz negativa.
    if (t1>0)
        t=t1
    else
        t=t2

    x_max=v_o*(cos(angu_o*pi/180))*t; //mide la distancia en x que a avanzado hasta t.
    y_max=h1+v_o*sin(angu_o*pi/180)*t-g/2*pow(t,2); //mide la distancia en y que a avanzado hasta t.

    if (x_max==(d-0.05) || x_max==(d-0.04) || x_max==(d-0.03) || x_max==(d-0.02) || x_max==(d-0.01) || x_max==d){ //el disparo alcanza al cañón.

        x(t_0)=v_o*(cos(angu_o*pi/180))*t_0; //mide la distancia en x que a avanzado hasta t=2,5.
        y(t_0)=h1+v_o*sin(angu_o*pi/180)*t_0-g/2*pow(t_0,2); //mide la distancia en y que a avanzado hasta t=2,5.
        y_max_D=h1+v_o*sin(angu_o*pi/180)*t_0-g/2*pow(t_0,2);
        x_max_D=v_o*(cos(angu_o*pi/180))*t_0;


    }
    else{ //el disparo no alcanza al cañón.
        cout << "El disparo ofensivo no afecta su cañon, no necesita lanzar un cañon" << endl;
    }




    return 0;
}
