#include "Macierz3D.hh"

Macierz3D Rotacja(double kat)
{
    Macierz3D Temp;
    double radian = kat * M_PI/180;
    
    Temp[0][0]= cos(radian);
    Temp[0][1]= -sin(radian);
    Temp[0][2]= 0;
    Temp[1][0]=sin(radian);
    Temp[1][1]=cos(radian);
    Temp[1][2]=0;
    Temp[2][0]=0;
    Temp[2][1]=0;
    Temp[2][2]=1;

    return Temp;
}