#include <iostream>

using namespace std;

int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_numbers, qtd_queries, ini, end, aux;
    unsigned long int *numbers;

    cin >> qtd_numbers >> qtd_queries;

    numbers = new unsigned long int[qtd_numbers];

    cin >> numbers[0];
    for (int i = 1; i < qtd_numbers; i++) {
        cin >> aux;
        numbers[i] = numbers[i - 1] + aux;
    }

    for (int i = 0; i < qtd_queries; i++) {
        cin >> ini >> end;
        cout << numbers[end - 1] - (ini - 2 < 0 ? 0 : numbers[ini - 2]) << "\n";
    }
}
