#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int value, qtd_diff_coins, qtd_min_coins_current, qtd_min_coins_old;
    const int INF = 1e9;

    cin >> qtd_diff_coins >> value;

    vector<int> min_coins_dp(value + 1, INF);
    vector<int> coins(qtd_diff_coins);

    for (int i = 0; i < qtd_diff_coins; i++)
        cin >> coins[i];

    min_coins_dp[0] = 0;

    for (int i = 0; i <= value; i++) {
        if (min_coins_dp[i] == INF) continue;
        for (int j = 0; j < qtd_diff_coins; j++) {
            if (i + coins[j] > value) continue;
            qtd_min_coins_old = min_coins_dp[i + coins[j]];
            qtd_min_coins_current = min_coins_dp[i] + 1;
            min_coins_dp[i + coins[j]] = (qtd_min_coins_current < qtd_min_coins_old) ? qtd_min_coins_current : qtd_min_coins_old;
        }
    }

    cout << (min_coins_dp[value] == INF ? -1 : min_coins_dp[value]) << "\n";

    return 0;
}