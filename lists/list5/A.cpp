#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int number, count, almostPrime = 0;
    bool *isPrime;

    cin >> number;
    isPrime = new bool[number + 1];

    for (int i = 0; i <= number; i++)
        isPrime[i] = true;
    
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= number; i++) {
        if (isPrime[i])
            for (int p = i * i; p <= number; p += i)
                isPrime[p] = false;
    }

    for (int i = 2; i <= number; i++) {
        count = 0;
        for (int k = 2; k * k <= i; k++) {
            if (i % k == 0) {
                if (isPrime[k]) count++;
                if (isPrime[i/k] && k * k != i) count++;
            }
            if (count > 2) break;
        }
        if (count == 2) almostPrime++;
    }

    cout << almostPrime << "\n";

    return 0;
}
