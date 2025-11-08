#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length, qtdQueries, option, number, count = 0;
    cin >> length >> qtdQueries;

    int *list = new int[length];
    for (int i = 0; i < length; i++){
        cin >> list[i];
        if (list[i] == 1)
            count++;
    }

    for (int i = 0; i < qtdQueries; i++) {
        cin >> option >> number; 
        if (option == 1){
           list[number - 1] = 1 - list[number - 1];
           if (list[number - 1] == 1)
               count++;
           else
               count--;
        }
        else
            if (number > count)
                cout << "0\n";
            else
                cout << "1\n";
    }

    delete [] list;

    return 0;
}
