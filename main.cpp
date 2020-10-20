#include <iostream>
#include <math.h>
#include<stdlib.h>
#include<time.h>
#define pi 3.1416
#define r_des_D 0.025
#define r_des_O 0.05
#define g 9.81
#define t_0 2.5

using namespace std;
float x_max(int velo_inicial, int angulo, int tiempo);
float y_max(int posicion, int velo_inicial, int angulo, int tiempo);

int main()
{
    float v_o, angu_o, h1, h2, d, x_max_O, y_max_O, a, b, c, t1, t2, t, x_max_D, y_max_D;
    cout << "Sistema de control de disparo defensivo" << endl;
    cout << endl;
    cout << "Ingrese la velocidad inicial del canion enemigo: ";
    cin >> v_o;
    cout << "Ingrese el angulo del canion enemigo: ";
    cin >> angu_o;
    cout << "Ingrese la altura del canion ofensivo: ";
    cin >> h1;
    cout << "Ingrese la distancia desde el canion ofensivo hasta el defensivo: ";
    cin >> d;
    cout << "Ingrese la altura del canion defensivo: ";
    cin >> h2;

    a=g/2; //parte de grado 2 de y(t).
    b=v_o*sin(sin(angu_o*pi/180)); //parte de grado 1 de y(t).
    c=h1; //parte constante de y(t).
    t1=(-b+sqrt((pow(b,2))-4*(-a)*c))/(2*a); //función cuadrática con raíz positiva.
    t2=(-b-sqrt((pow(b,2))-4*(-a)*c))/(2*a); //función cuadrática con raíz negativa.
    if (t1>0)
        t=t1;
    else
        t=t2;


    x_max_O=x_max(v_o,angu_o,t); //mide la distancia en x que ha avanzado hasta t.
    y_max_O=y_max(h1,v_o,angu_o,t); //mide la distancia en y que ha avanzado hasta t.

    if (x_max_O>=(d-r_des_O) && (y_max_O>=(h2-r_des_O) && y_max_O<=(h2+r_des_O))){ //el disparo alcanza al cañón.
        float angu_D,v_oD;
        cout << "Ingrese el angulo del canion defensivo: ";
        cin >> angu_D;
        t=1;
        for (a=0;a<3;a++){
            v_oD=(v_o*cos(angu_o*pi/180)*(t+2.5))/(cos(angu_D*pi/180)*t); //encuentra la velocidad inicial en HD.
            x_max_D=x_max(v_oD,angu_D,t); //mide la posición final en x para que explote la bala.
            y_max_D=y_max(h2,v_oD,angu_D,t); //mide la posición final en y para que explote la bala.

            cout << "Con velocidad inicial de: " << v_oD << ", angulo de: " << angu_D << " y un tiempo poximado de: " << t;
            cout<<"s, se estrellan las balas." << endl;
            t++;
        }
    }
    else{ //el disparo no alcanza al cañón.
        cout << "El disparo ofensivo no afecta su canion, no necesita lanzar una bala" << endl;
    }

    return 0;
}

float x_max(int velo_inicial, int angulo, int tiempo){
    int x_max;
    x_max=velo_inicial*(cos(angulo*pi/180))*tiempo;

    return x_max;
}

float y_max(int altura, int velo_inicial, int angulo, int tiempo){
    int y_max;
    y_max=altura+velo_inicial*sin(angulo*pi/180)*tiempo-g/2*pow(tiempo,2);

    return y_max;
}
