#include <iostream>
#include <algorithm>

#define llint long long int

using namespace std;

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llint queries, nPopulation, aux, sumMoney, money;
    llint* population;

    cin >> queries;

    while (queries--) {
        cin >> nPopulation;
        population = new llint[nPopulation];
        sumMoney = 0;
        for (int i = 0; i < nPopulation; i++){
            cin >> aux; 
            population[i] = aux;
            sumMoney += aux;
        }
        if (nPopulation < 3) {
            cout << "-1\n";
            continue;
        }
        sort(population, population + nPopulation);
        money = population[nPopulation/2] * 2 * nPopulation - sumMoney + 1; 
        cout << (money < 0 ? 0 : money) << "\n";
        delete [] population;
    }

}
