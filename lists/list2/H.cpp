#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_numbers, goal, aux;
    int* numbers;
    map<int, int> checkds;

    cin >> qtd_numbers >> goal;

    numbers = new int[qtd_numbers];

    for (int i = 0; i < qtd_numbers; i++) {
        cin >> numbers[i];
        checkds[numbers[i]] = i;
    }

    for (int i = 0; i < qtd_numbers; i++){
        for (int j = i + 1; j < qtd_numbers; j++) {
            aux = numbers[i] + numbers[j]; 
            if (aux >= goal) continue;
            if(checkds.count(goal - aux) && checkds[goal - aux] != i && checkds[goal - aux] != j){
                cout << i + 1 << " " << checkds[goal-aux] + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << "\n";
    
    return 0;
}
