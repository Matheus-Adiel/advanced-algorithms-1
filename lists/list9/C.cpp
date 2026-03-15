#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_stones, qtd_jumps, min, current_cust;

    cin >> qtd_stones >> qtd_jumps;

    vector<int> height_stones(qtd_stones);
    vector<int> cust_dp(qtd_stones, -1);

    for (int i = 0; i < qtd_stones; i++)
        cin >> height_stones[i];

    cust_dp[0] = 0; 

    for (int i = 1; i < qtd_stones; i++) {
        min = -1;
        for (int k = 1; k <= qtd_jumps && i - k >= 0; k++) {
            current_cust = cust_dp[i - k] + abs(height_stones[i - k] - height_stones[i]);
            if (current_cust < min || min == -1)
                min = current_cust;
        }
        cust_dp[i] = min;
    }

    cout << cust_dp[qtd_stones - 1] << "\n";

    return 0;
}