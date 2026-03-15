#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_monsters;

    cin >> qtd_monsters;

    vector<long long int> exp_monsters(qtd_monsters + 1, 0);
    vector<vector<long long int>> dp(2, vector<long long int>(qtd_monsters + 1, 0));

    for (int i = 1; i <= qtd_monsters; i++)
        cin >> exp_monsters[i];

    dp[0][1] = exp_monsters[1];
    dp[1][1] = 0;

    for (int i = 2; i <= qtd_monsters; i++) {
        long long int monster_is_odd_defeat = dp[1][i - 1] + exp_monsters[i];
        long long int monster_is_odd_let = dp[0][i - 1];
        dp[0][i] = max(monster_is_odd_defeat, monster_is_odd_let);

        long long int monster_is_pair_defeat = dp[0][i - 1] + exp_monsters[i] * 2;
        long long int monster_is_pair_let = dp[1][i - 1];
        dp[1][i] = max(monster_is_pair_defeat, monster_is_pair_let);
    }

    cout << max(dp[0][qtd_monsters], dp[1][qtd_monsters]) << "\n";

    return 0;
}
