#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> num_dices_comb_dp(n + 1, 0);

    num_dices_comb_dp[0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int d = 1; d <= 6 && i + d <= n; d++)
            num_dices_comb_dp[i + d] = (num_dices_comb_dp[i + d] + num_dices_comb_dp[i]) % 1000000007;
    }

    cout << num_dices_comb_dp[n] << "\n";

    return 0;
}