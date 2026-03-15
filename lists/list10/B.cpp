#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int euclideanDistanceSquared(int point1, int point2, vector<int> &x, vector<int> &y) {
    return pow(x[point1] - x[point2], 2) + pow(y[point1] - y[point2], 2);
}

bool isRightTriangle(vector<int> &x, vector<int> &y) {
    int AB = euclideanDistanceSquared(0, 1, x, y);
    int AC = euclideanDistanceSquared(0, 2, x, y);
    int CB = euclideanDistanceSquared(1, 2, x, y);

    if (AB == AC + CB) return true;
    if (AC == AB + CB) return true;
    if (CB == AB + AC) return true;
    return false;
}

int main() {

    vector<int> x(3);
    vector<int> y(3);

    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];


    cout << (isRightTriangle(x, y) ? "Yes" : "No") << "\n";
    
    return 0;
}