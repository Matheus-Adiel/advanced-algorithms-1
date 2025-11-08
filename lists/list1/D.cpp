#include <iostream>
#include <cmath>

using namespace std;

int main() {

    const int NBITS = 64;

    int *bits = new int[NBITS];
    unsigned long long int sum = 0;

    for (int i = 0; i < NBITS; i++)
        cin >> bits[i];

    for (int i = 0; i < NBITS; i++)
        if (bits[i] == 1)
            sum += (1ULL << i);

    cout << sum << "\n";

    delete [] bits;

    return 0;
}
