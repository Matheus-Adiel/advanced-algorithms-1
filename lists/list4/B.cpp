#include <iostream>
#include <map>

using namespace std;

int main() {

    long long qtd_numbers, goal, current, count, aux;
    map<long long, long long> checkeds;
    
    cin >> qtd_numbers >> goal;
    checkeds[0] = 1;
    current = 0;
    count = 0;

    for (int i = 0; i < qtd_numbers; i++) {
        cin >> aux;
        current += aux;
        if (checkeds.count(current - goal))
            count += checkeds[current - goal];
        if (checkeds.count(current))
            checkeds[current] += 1;
        else
            checkeds[current] = 1;
    }
    
    cout << count << "\n";
    return 0;
}
