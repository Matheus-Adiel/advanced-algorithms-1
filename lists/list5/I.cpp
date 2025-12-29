#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int MAX = 1e8;
    int count = 0;
    bool *is_prime = new bool[MAX + 1];

    for (int i = 0; i <= MAX; i++)
        is_prime[i] = true;

    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++)
        if (is_prime[i])
            for (int p = i * i; p <= MAX; p += i)
                is_prime[p] = false;

    for (int i = 1; i <= MAX; i++)
        if (is_prime[i]) {
            count++;
            if (count % 100 == 1) cout << i << "\n"; 
        }

    delete [] is_prime;
    return 0;
}
