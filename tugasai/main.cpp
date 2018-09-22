#include <iostream>
#include <cmath>
#include <time.h>
#include <cstdlib>
using namespace std;
double fungsi (double x, double y){
    return -abs(sin(x)*cos(y)*exp(abs(1-sqrt(pow(x,2)+pow(y,2))/M_PI)));
}
double fRand(double fMin, double fMax){
    double f = (double)rand() / (double)RAND_MAX;
    return fMin + f * (fMax - fMin);
}
int main()
{
    srand(time(0));
    double x,y,xs,ys,nilai,nilais,Temp,e;
    x = fRand(-10,10);
    y = fRand(-10,10);
    Temp = 100;
    nilai=fungsi(x,y);
    while(Temp>0.03){
        xs=fRand(-10,10);
        ys=fRand(-10,10);
        nilais=fungsi(xs,ys);
        if(nilais<nilai){
            x=xs;
            y=ys;
            nilai=nilais;
        }else{
            e=nilais-nilai;
            if(exp(-e/Temp)>fRand(0,1)){
                x=xs;
                y=ys;
                nilai=nilais;
            }
        }
        Temp-=0.0039346;
    }
    cout<<"Solusi x : "<<x<<endl;
    cout<<"Solusi y : "<<y<<endl;
    cout<<"Nilai : "<<nilai<<endl;
    cout<<"Temp : "<<Temp<<endl;
    return 0;
}
