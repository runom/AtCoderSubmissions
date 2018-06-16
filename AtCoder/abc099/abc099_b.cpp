#include <iostream>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    int d = b - a;

    cout << (d * (d + 1) / 2 - b) << endl;
}