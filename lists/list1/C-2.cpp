#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    int prime; 
    bool *listPrimes;

    cin >> prime;

    listPrimes = new bool[prime];

    listPrimes[0] = false;
    listPrimes[1] = false;

    for (int i = 0; i < prime; i++)
        listPrimes[i] = true;

    for (int i = 2; i < prime; i++)
        if (listPrimes[i] == true)
            for (int j = 2; i * j < prime; j++)
                listPrimes[i*j] = false; 

   for (int i = 2; i <= prime/2; i++)
        if (listPrimes[i] == true && listPrimes[prime - i] == true){
            cout << i << " " << prime - i << "\n";
            delete [] listPrimes;
            return 0;
        }

    cout << "-1\n";

    delete [] listPrimes;

    return 0;
}
