#include <iostream>
#include <cmath>

using namespace std;

unsigned long long lamps_on (unsigned long long qtd_lamps) {
    unsigned long long lamps_off = sqrt(qtd_lamps);
    if (lamps_off * lamps_off > qtd_lamps) lamps_off--;
    else if ((lamps_off + 1) * (lamps_off + 1) <= qtd_lamps) lamps_off++;
    unsigned long long lamps_on = qtd_lamps - lamps_off;
    return lamps_on;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries;
    unsigned long long goal_lamps_on, ini, end, mid; 

    cin >> queries;

    while (queries--){
        cin >> goal_lamps_on;
        ini = goal_lamps_on;
        end = goal_lamps_on * 2;
        while (lamps_on(end) < goal_lamps_on){
            ini = end + 1;
            end *= 2;
        }
        while (ini < end){
            mid = (ini + end)/2;
            if (lamps_on(mid) >= goal_lamps_on) end = mid;
            else ini = mid + 1;
        }
        cout << ini << "\n";
    }

    return 0;
}
