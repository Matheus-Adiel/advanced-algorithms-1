#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    int count, max_count;
    stack<char> myStack;
    map<int, int> count_max;

    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            myStack.push('(');
            count++;
        } else {
            if (myStack.empty()) {
                count = 0;
                myStack = stack<char>();
            } else count++;
        }
        if (count > max_count) {
            max_count = count;
            count_max[max_count]++;
        }
    }

    if (max_count == 0)
        cout << "0 1";
    else
        cout << max_count << " " << count_max[max_count];
    cout << "\n";

    return 0;
}
