#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int egg_mins, small_box, med_box, large_box, new_cust, old_cust, min;
    const int INF = 1e9;

    cin >> egg_mins >> small_box >> med_box >> large_box;

    vector<int> length_box({6, 8, 12});
    vector<int> cust_box({small_box, med_box, large_box});
    vector<int> cust_dp(egg_mins + 12 + 1, INF);

    cust_dp[0] = 0;

    for (int i = 0; i <= egg_mins; i++) {
        for (int j = 0; j < 3; j++) {
            new_cust =  cust_dp[i] + cust_box[j];
            old_cust = cust_dp[i + length_box[j]];
            cust_dp[i + length_box[j]] = old_cust < new_cust ? old_cust : new_cust; 
        }
    }

    min = cust_dp[egg_mins];
    for (int i = egg_mins + 1; i <= egg_mins + 12; i++)
       if (cust_dp[i] < min) min = cust_dp[i];

    cout << min << "\n";

    return 0;
}