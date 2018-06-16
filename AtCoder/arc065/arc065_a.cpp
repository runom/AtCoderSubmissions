#include <iostream>
#include <string>
#include <regex>
 
using namespace std;
 
int main() {
    string s;
    cin >> s;
 
    cout << (regex_match(s, regex("^(dream|dreamer|erase|eraser)*$"))
                 ? "YES"
                 : "NO")
         << endl;
}