#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries, n, x;
    cin >> queries;

    while (queries--) {
        cin >> n;
        vector<int> dp(n + 1, -1);

        for (int i = 0; i < n; i++) {
            cin >> x;
            dp[x] = 1;
        }

        for (int i = 2; i*i <= n; i++) {
            if (dp[i] == -1) continue;
            for (int j = i; i*j <= n; j++) {
                if (dp[j] != -1) {
                    int current_multiplies = dp[i*j];
                    int new_multiplies = dp[i] + dp[j];
                    dp[i*j] = (current_multiplies != -1 && current_multiplies <= new_multiplies) ? current_multiplies : new_multiplies;
                }
            }
        }

        for (int i = 1; i < n; i++)
            cout << dp[i] << " ";
        cout << dp[n] << "\n";

    }

    return 0;
}