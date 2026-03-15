#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries, qtd_palitos, length_palito;
    string result;

    cin >> queries;

    while (queries--) {
        cin >> qtd_palitos;

        vector<int> pares_palitos;
        map<int, int> freq_palitos;
        for (int i = 0; i < qtd_palitos; i++) {
            cin >> length_palito;
            freq_palitos[length_palito]++;
            if (freq_palitos[length_palito] >= 2) {
                pares_palitos.push_back(length_palito);
                freq_palitos[length_palito] = 0;
            }
        }

        vector<int> impar_palitos;
        for (pair<int, int> palito : freq_palitos)
            if (palito.second > 0) impar_palitos.push_back(palito.first);

        if (pares_palitos.size() >= 2) {
            cout << pares_palitos[0] << " " << pares_palitos[0] << " ";
            cout << pares_palitos[1] << " " << pares_palitos[1] << "\n";
        } else if (pares_palitos.size() == 1) {
            sort(impar_palitos.begin(), impar_palitos.end());
            sort(pares_palitos.begin(), pares_palitos.end());
            int i = 0;
            int maior_par = pares_palitos[pares_palitos.size() -1];
            bool ehPossivel = false;
            while (i < impar_palitos.size() - 1 && !ehPossivel) {
               ehPossivel = 2*maior_par + impar_palitos[i] > impar_palitos[i + 1];
               i++;
            }
            if (ehPossivel) {
               cout << pares_palitos[0] << " " << pares_palitos[0] << " ";
               cout << impar_palitos[i - 1] << " " << impar_palitos[i] << "\n";
            } else {
                cout << "-1\n";
            }
        } else {
            cout << "-1\n";
        }

    }

    return 0;
}