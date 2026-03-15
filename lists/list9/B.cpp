#include <iostream>
#include <vector>

using namespace std;

int cust_stone(vector<int> &height_stones, vector<int>&cust, int n_stone) {

    if (n_stone == 0) return 0;
    if (n_stone == 1) return abs(height_stones[n_stone - 1] - height_stones[n_stone]);
    if (cust[n_stone] != -1) return cust[n_stone];
    
    int stone_before_1 = cust_stone(height_stones, cust, n_stone - 1) + abs(height_stones[n_stone - 1] - height_stones[n_stone]);
    int stone_before_2 = cust_stone(height_stones, cust, n_stone - 2) + abs(height_stones[n_stone - 2] - height_stones[n_stone]);

    cust[n_stone] = min(stone_before_1, stone_before_2);

    return min(stone_before_1, stone_before_2);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_stones;

    cin >> qtd_stones;

    vector<int> height_stones(qtd_stones);
    vector<int> cust(qtd_stones, -1);

    for (int i = 0; i < qtd_stones; i++)
        cin >> height_stones[i];

    cout << cust_stone(height_stones, cust, qtd_stones - 1) << "\n";

    return 0;
}