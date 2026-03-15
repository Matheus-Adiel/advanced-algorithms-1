#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    long long queries, out, mod = 1000000007;
    long long n[3];
    cin >> queries;

    while (queries--) {
        cin >> n[0] >> n[1] >> n[2];
        sort(n, n + 3);

        for (int i = 0; i < 3; i++)
            n[i] = (n[i] - i) % mod;
        
        out = (n[0] * n[1]) % mod;
        out = (out * n[2]) % mod;
        cout << out << "\n";
    }

    return 0;
}
