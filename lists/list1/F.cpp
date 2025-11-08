#include <iostream>

using namespace std;

int countABC(string token, int tokenLength, int ini, int end) { 
    int count = 0;
    if (ini < 0)
        ini = 0;
    if (end > tokenLength - 3)
        end = tokenLength - 3;
    for (int i = ini; i <= end; i++)
        if (token[i] == 'A' && token[i + 1] == 'B' && token[i + 2] == 'C')
            count++;
    return count;
}

int main() {

    int stringLength, qtdQueries, indexAux, countAux, count = 0;
    string token;
    char charAux;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> stringLength >> qtdQueries >> token;

    count = countABC(token, stringLength, 0, stringLength - 2);

    for (int i = 0; i < qtdQueries; i++) {
        cin >> indexAux >> charAux;
        indexAux -= 1;
        countAux = countABC(token, stringLength, indexAux - 2, indexAux + 2);
        token[indexAux] = charAux;
        count += countABC(token, stringLength, indexAux - 2, indexAux + 2) - countAux;
        cout << count << "\n";
    }

}
