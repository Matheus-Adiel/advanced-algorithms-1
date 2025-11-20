#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_a, qtd_b, ini, end, mid, goal;
    int* numbers_a; 
    int* numbers_b;

    cin >> qtd_a >> qtd_b;
    numbers_a = new int[qtd_a];
    numbers_b = new int[qtd_b];
    for (int i = 0; i < qtd_a; i++)
        cin >> numbers_a[i];
    for (int i = 0; i < qtd_b; i++)
        cin >> numbers_b[i];

    sort(numbers_a, numbers_a + qtd_a);
   
    for (int i = 0; i < qtd_b; i++) { 
        ini = 0;
        end = qtd_a - 1;
        goal = numbers_b[i];
        while (ini < end) {
            mid = (ini + end)/2;
            if (numbers_a[mid] <= goal) 
                ini = mid + 1;
            else 
                end = mid - 1;
        }
        cout << ((numbers_a[ini] <= goal) ? ini + 1 : ini);
        if (i != qtd_b - 1) cout << " ";
        else cout << "\n";
    }

    delete [] numbers_a;
    delete [] numbers_b;
    return 0;
}
