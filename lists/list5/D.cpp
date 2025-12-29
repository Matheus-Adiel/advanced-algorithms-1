#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int MAX = 1000000;
    int queries, goal;
    long long *divisorsCount = new long long[MAX + 1];

    for (int i = 1; i <= MAX; i++)
        for (int j = i; j <= MAX; j += i)
            divisorsCount[j] += 1;

    cin >> queries;

    while(queries--) {
        cin >> goal;
        cout << divisorsCount[goal] << "\n";
    }

    delete [] divisorsCount;

    return 0;
}
