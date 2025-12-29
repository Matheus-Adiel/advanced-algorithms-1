#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int MAX = 500000;
    int queries, goal;
    long long *divisorSum = new long long[MAX + 1];

    for (int i = 1; i <= MAX / 2; i++)
        for (int j = i * 2; j <= MAX; j += i)
            divisorSum[j] += i;

    cin >> queries;

    while(queries--) {
        cin >> goal;
        cout << divisorSum[goal] << "\n";
    }

    delete [] divisorSum;

    return 0;
}
