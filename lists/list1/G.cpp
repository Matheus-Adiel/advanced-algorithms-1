#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length, qtdremoves, smaller, range;
    cin >> length >> qtdremoves;
    vector<int> numbers(length);

    for (int i = 0; i < length; i++)
        cin >> numbers[i]; 

    sort(numbers.begin(), numbers.end());
    smaller = numbers[length - 1];
    range = length - qtdremoves - 1;

    for (int i = 0; i + range < length; i++) 
        if ((numbers[i + range] - numbers[i]) < smaller)
            smaller = numbers[i + range] - numbers[i];

    cout << smaller << "\n";

    return 0;
}
