#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, value, maior = 0;

    cin >> n;
    map<int, int> sequences;

    while (n--) {
        cin >> value;
        sequences[value] = sequences[value - 1] + 1;
        if (sequences[value] > maior)
            maior = sequences[value];
    }

    cout << maior << "\n";

    return 0;
}