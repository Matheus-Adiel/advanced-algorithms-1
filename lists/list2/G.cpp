#include <iostream>
#include <set>

using namespace std;

int main() {

    int qtd_nums, aux, count = 0, ini = 0, max_count = 0;
    int* numbers;
    set<int> numbers_set;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> qtd_nums;

    numbers = new int[qtd_nums];

    for (int i = 0; i < qtd_nums; i++)
        cin >> numbers[i];

    for (int i = 0; i < qtd_nums; i++) {
        if (numbers_set.count(numbers[i]) == 0) {
            count++;
            numbers_set.insert(numbers[i]);
        } else {
            while (numbers[ini] != numbers[i]){
                numbers_set.erase(numbers_set.find(numbers[ini++]));
                count--;
            }
            ini++;
        }
        if (count > max_count) max_count = count;
    }

    cout << max_count << "\n";

    delete [] numbers;
    return 0; 

}
