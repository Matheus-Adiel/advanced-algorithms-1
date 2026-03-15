#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long queries, number, resto;

    cin >> queries;

    while (queries--) {
        cin >> number;
        resto = number % 11;
        cout << (resto * 111 <= number ? "YES" : "NO") << "\n";
    }

    return 0;
}