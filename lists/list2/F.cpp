#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_elements, leftBorder, rigthBorder;
    unsigned long long int sumA = 0, sumB = 0, maxSum = 0;
    int* numbers;
    
    cin >> qtd_elements;
    numbers = new int[qtd_elements];
    leftBorder = -1;
    rigthBorder = qtd_elements;

    for (int i = 0; i < qtd_elements; i++)
        cin >> numbers[i];

    while (leftBorder < rigthBorder) {
       leftBorder++;
       sumA += numbers[leftBorder];
       while (sumB < sumA) {
           rigthBorder--;
           if (rigthBorder == -1) break;
           sumB += numbers[rigthBorder];
       }
       if (sumA == sumB && leftBorder < rigthBorder)
           maxSum = sumA;
    }

    cout << maxSum << "\n";
    delete [] numbers;
    return 0;
    
}
