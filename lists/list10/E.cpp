#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries, l1, b1, l2, b2, l3, b3, A_total;
    bool result;

    cin >> queries;

    while(queries--) {
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        if (l1 == l2 && l2 == l3 && (b1 + b2 + b3) == l1)
            result = true;
        else if (b1 == b2 && b2 == b3 && (l1 + l2 + l3) == b1)
            result = true;
        else if ((l2 == l3) && b1 == (b2 + b3) && (l1 + l2) == b1)
            result = true;
        else if ((b2 == b3) && l1 == (l2 + l3) && (b1 + b2) == l1)
            result = true;
        else
            result = false;
        cout << (result ? "YES" : "NO") << "\n";
    }
    
    return 0;
}