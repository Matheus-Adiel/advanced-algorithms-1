#include <iostream>
#include <map>
#include <utility>

using namespace std;

#define ll long long

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll qtd_numbers, goal, miss, sum, i, j, k, l;
    ll *numbers;
    map<ll, pair<ll, ll>> registers;

    cin >> qtd_numbers >> goal;
    numbers = new ll[qtd_numbers];

    for (int i = 0; i < qtd_numbers; i++)
        cin >> numbers[i];

    for (i = 0; i < qtd_numbers; i++) {
        for (j = i + 1; j < qtd_numbers; j++) {
            sum = numbers[i] + numbers[j];
            registers[sum] = pair<ll, ll>(i, j);
        }
    }

    for (i = 0; i < qtd_numbers; i++) {
        for (j = i + 1; j < qtd_numbers; j++) {
            sum = numbers[i] + numbers[j];
            miss = goal - sum;
            if (registers.count(miss)){
                k = registers[miss].first;
                l = registers[miss].second;
                if (i != k && i != l && j != k && j != l) {
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << "\n";
                    delete [] numbers;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    delete [] numbers;
    return 0;
}
