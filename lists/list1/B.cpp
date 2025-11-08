#include <iostream>

using namespace std;

int main() {
    int h, v, smaller;
    string out;
    cin >> h >> v;
    if (h < v)
        smaller = h;
    else
        smaller = v;
    cout << (smaller % 2 != 0 ? "Akshat\n" : "Malvika\n");
}
