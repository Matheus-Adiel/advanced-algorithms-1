#include <iostream>

using namespace std;

bool isPalindrome(string P) {
    for (int i = 0; i < P.length()/2; i++)
        if (P[i] != P[P.length() - i - 1])
            return false;
    return true;
}

int main() {
    
    int A, B, count = 0;

    cin >> A >> B;

    for (int i = A; i <= B; i++)
        if (isPalindrome(to_string(i)))
            count++;

    cout << count << "\n";
}
