#include <iostream>

using namespace std;

int main() {

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_cows, qtd_queries, aux, ini, end;
    int *breeds[3];

    cin >> qtd_cows >> qtd_queries;

    breeds[0] = new int[qtd_cows];
    breeds[1] = new int[qtd_cows];
    breeds[2] = new int[qtd_cows];

    cin >> aux;
    breeds[aux - 1][0] = 1;
    breeds[aux % 3][0] = 0; 
    breeds[(aux + 1) % 3][0] = 0; 
    for (int i = 1; i < qtd_cows; i++) {
        cin >> aux;
        breeds[aux - 1][i] = breeds[aux - 1][i - 1] + 1;
        breeds[aux % 3][i] = breeds[aux % 3][i - 1];
        breeds[(aux + 1) % 3][i] = breeds[(aux + 1) % 3][i - 1];
    }

    for (int i = 0; i < qtd_queries; i++) {
       cin >> ini >> end;
       cout << (breeds[0][end - 1] - (ini < 2 ? 0 : breeds[0][ini - 2])) << " "
            << (breeds[1][end - 1] - (ini < 2 ? 0 : breeds[1][ini - 2])) << " "
            << (breeds[2][end - 1] - (ini < 2 ? 0 : breeds[2][ini - 2])) << "\n";
    }

    delete [] breeds[0];
    delete [] breeds[1];
    delete [] breeds[2];

}
