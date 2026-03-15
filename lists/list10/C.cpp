#include <iostream>
#include <vector>

using namespace std;

int main() {

    int qtd_points, x_point, y_point;
    bool isCollinear;
    vector<int> x;
    vector<int> y;

    cin >> qtd_points;

    while (qtd_points--) {
        cin >> x_point >> y_point;
        x.push_back(x_point);
        y.push_back(y_point);
    }

    isCollinear = false;

    for (int i = 0; i < x.size(); i++) {
        for (int j = i + 1; j < x.size(); j++) {
            for (int k = j + 1; k < x.size(); k++) {
                if (((y[i] - y[j])*(x[i] - x[k])) == ((y[i] - y[k])*(x[i] - x[j]))) {
                    isCollinear = true; 
                }
            }
            if (isCollinear) break;
        }
        if (isCollinear) break;
    }

    cout << (isCollinear ? "Yes" : "No") << "\n";
    
    return 0;
}