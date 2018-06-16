#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a, b, c;

double f(double t) {
    return a*t + b*sin(c*t*acos(-1));
}

int main(){
    cin >> a >> b >> c;
    
    double l = 0;
    double r = 1000;
    
    for(int i = 0; i < 100; ++i){
        double m = (l + r)/2;
        double y = f(m);
        if(y < 100) {
            l = m;
        } else {
            r = m;
        }
    }
    
    printf("%.10f\n", r);
}