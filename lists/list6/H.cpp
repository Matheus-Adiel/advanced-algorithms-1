#include <iostream>

using namespace std;

long long expBinaria(long long base, long long exp, long long mod) {
    if (exp == 0)
        return 1;
    if (exp % 2 != 0)
        return (base * expBinaria(base, exp - 1, mod)) % mod;
    long long aux = expBinaria(base, exp/2, mod);
    return (aux * aux) % mod;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long queries, qtdDigits, mod = 1000000007;
    cin >> queries;

    while(queries--) {
        cin >> qtdDigits;
        cout << (5 * expBinaria(2, qtdDigits, mod)) % mod << "\n"; 
    }

    return 0;

}
