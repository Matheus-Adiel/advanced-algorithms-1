#include <iostream>
#include <cstdio>

using namespace std;

bool isPrime(int prime) {
    if (prime == 1 || prime == 0)
        return false;
    for (int i = 2; i*i <= prime; i++)
        if (prime % i == 0)
            return false;
    return true;
}

int main() {

    int prime;

    cin >> prime;

    for (int i = 2; i <= prime/2; i++)
        if (isPrime(i))
            if (isPrime(prime - i)){
                cout << i << " " << prime - i << "\n";
                return 0;
            }

    cout << "-1\n";

    return 0;
}
