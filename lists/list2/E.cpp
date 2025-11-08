#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_numbers, goal, aux, missing;
    map<int, int> checkeds;

    cin >> qtd_numbers >> goal;

    for (int i = 0; i < qtd_numbers; i++) {
        cin >> aux;
        missing = goal - aux;
        if (checkeds.count(missing)) {
            cout << checkeds[missing] + 1 << " " << i + 1 << "\n";
            return 0;
        } else {
            checkeds[aux] = i;
        }
    }
    
    cout << "IMPOSSIBLE\n";

    return 0;
}
