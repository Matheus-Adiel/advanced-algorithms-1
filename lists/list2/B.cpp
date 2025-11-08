#include <iostream>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int qtd_tests, qtd_numbers, qtd_queries, ini, end, k, aux;
    int *numbers;

    cin >> qtd_tests;

    for (int i = 0; i < qtd_tests; i++) {
        cin >> qtd_numbers >> qtd_queries;
        numbers = new int[qtd_numbers];
        
        cin >> numbers[0];
        for (int j = 1; j < qtd_numbers; j++) {
            cin >> aux;
            numbers[j] = numbers[j - 1] + aux;
        }

        for (int j = 0; j < qtd_queries; j++) {
            cin >> ini >> end >> k;
            aux = numbers[end - 1] - (ini < 2 ? 0 : numbers[ini - 2]);
            cout << ((numbers[qtd_numbers - 1] - aux + k*(ini - end + 1)) % 2 == 0 ? "NO" : "YES") << "\n";
        }

        delete [] numbers;
    }
}
