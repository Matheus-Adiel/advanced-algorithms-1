#include <iostream>
#include <map>

using namespace std;

int main() {

    long long qtd_numbers, current, count, aux, rest;
    map<long long, long long> checkeds;
    
    cin >> qtd_numbers;
    checkeds[0] = 1;
    current = 0;
    count = 0;

    for (int i = 0; i < qtd_numbers; i++) {
        cin >> aux;
        current += aux;
        rest = (current % qtd_numbers + qtd_numbers) % qtd_numbers;
        if (checkeds.count(rest))
            count += checkeds[rest];
        if (checkeds.count(rest))
            checkeds[rest] += 1;
        else
            checkeds[rest] = 1;
    }
    
    cout << count << "\n";
    return 0;
}
