#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int LIMIT = 100000000;
    int n;
    bool *is_prime = new bool[LIMIT + 1];
    vector<int> primes;

    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < LIMIT; i++)
        is_prime[i] = true;

   for (long long i = 2; i * i <= LIMIT; i++)
       if (is_prime[i])
           for (long long p = i * i; p <= LIMIT; p += i)
               is_prime[p] = false;

   for (int i = 2; i <= LIMIT; i++)
       if (is_prime[i]) primes.push_back(i);

    cin >> n;
    cout << primes[n - 1] << "\n";

    delete [] is_prime;
    return 0;
}
