#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long qtd_numbers, k, countLoop, indexMid;
    long long miss;
    long long* numbers;

    cin >> qtd_numbers >> k;
    numbers = new int[qtd_numbers];
    indexMid = qtd_numbers/2;

    for (int i = 0; i < qtd_numbers; i++)
        cin >> numbers[i];

    sort(numbers, numbers + qtd_numbers);

    for (int i = indexMid; i < qtd_numbers - 1; i++){
        countLoop = i - indexMid + 1;
        miss = numbers[i + 1] - numbers[i];
        miss *= countLoop;
        if (k < miss) 
            numbers[indexMid] += k/countLoop;
        else
            numbers[indexMid] += miss/countLoop;
        k -= miss;
        if (k <= 0) break;
    }

    if (k > 0)
        numbers[indexMid] += k/(indexMid + 1);

    cout << numbers[indexMid] << "\n";

}
