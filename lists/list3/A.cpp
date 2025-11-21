#include <iostream>

using namespace std;

long long int production (long long *machines, long long &size, long long int &temp, long long int &goal) {
    long long int sumProducts = 0;
    for (int i = 0; i < size; i++) {
       sumProducts += temp/machines[i];
       if (sumProducts >= goal)
           break;
    }
    return sumProducts;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long static MAX_TEMP = 1e18;
    long long goal, mid, ini = 0, end = MAX_TEMP;
    long long number_machines;
    long long* machines;

    cin >> number_machines >> goal;
    machines = new long long[number_machines];

    for (int i = 0; i < number_machines; i++)
        cin >> machines[i];

    while (ini < end) { 
        mid = (ini + end) / 2;
        if (production(machines, number_machines, mid, goal) < goal)
            ini = mid + 1;
        else 
            end = mid;
    }

    cout << ini << "\n";

}
