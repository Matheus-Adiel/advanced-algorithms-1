#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long queries, base, limit, aux;
    cin >> queries;

    while(queries--) {
        cin >> base >> limit;
        cout << ((limit/3) - ((base - 1)/3)) << "\n";
    }

    return 0;

}
