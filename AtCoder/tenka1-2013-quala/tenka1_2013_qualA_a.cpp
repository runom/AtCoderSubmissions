#include <iostream>
using namespace std;

int main()
{
    int n = 42;
    while(n < 130000000){
        n *= 2;
    }
    cout << n << endl;
}