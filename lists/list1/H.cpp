#include <iostream>

using namespace std;

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;

    cin >> n;

    if (n != 1)
        cout << n << " ";

    while (n != 1) {
        if (n % 2 == 0) 
            n /= 2;
        else 
            n = n * 3 + 1;
        if (n != 1)
            cout << n << " "; 
    }

    cout << n << "\n";

    return 0;
}
