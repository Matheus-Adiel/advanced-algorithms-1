#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    int count = 0, max_count = 0;
    stack<int> myStack;
    map<int, int> register_counts;

    cin >> input;
    myStack.push(-1);
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') myStack.push(i);
        else {
            myStack.pop();
            if (myStack.size() == 0) {
                myStack.push(i);
            } else {
                count = i - myStack.top();
                register_counts[count]++;
                if (max_count < count) max_count = count;
            }
        }
    }

    if (max_count == 0)
        cout << "0 1";
    else
        cout << max_count << " " << register_counts[max_count];
    cout << "\n";

    return 0;
}
