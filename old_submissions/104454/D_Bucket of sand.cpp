#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    long double h, d;
    cin >> h >> d;
    long double alfa = atan2l(d/2, h);
    long double PI = 3.14159265358979323846;
    long double beta = 124*PI/180-alfa;
    long double a = h*sinl(alfa)/sin(beta);
    long double b = a*cosl((long double)(34)*PI/ (long double)(180));
    cout << fixed << setprecision(10) << PI*b*b*h/3;
}
