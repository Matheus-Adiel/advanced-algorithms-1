#include <iostream>

using namespace std;

long long expBinaria(long long base, long long exp, long long mod) {
    if (exp == 0)
        return 1;
    if (exp % 2 == 1)
        return (base * expBinaria(base, exp - 1, mod)) % mod; 
    long long aux = expBinaria(base, exp/2, mod);
    return (aux * aux) % mod;

}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int queries, num;
    cin >> queries;

    while (queries--){
        cin >> num;
        cout << expBinaria(2, --num, 1000000007) << "\n";
    }

    return 0;

}
