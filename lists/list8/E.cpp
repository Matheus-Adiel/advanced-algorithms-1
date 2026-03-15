#include <iostream>
#include <list>
#include <utility>
#include <vector>

using namespace std;

int first(vector<pair<int, list<int>>> &dsu, int node) {
    if (dsu[node].first != node) {
        int aux = first(dsu, dsu[node].first);
        dsu[node].first = aux;
        return aux;
    }
    return dsu[node].first;
}

int first_distance(vector<pair<int, list<int>>> &dsu, int node) {
    int distance = 0;
    while (dsu[node].first != node) {
        distance++;
        node = dsu[node].first;
    }
    return distance;
}

void addEdge(vector<pair<int, list<int>>> &dsu, int node1, int node2) {
    int aux; 
    if (first_distance(dsu, node1) > first_distance(dsu, node2)) {
        aux = node1;
        node1 = node2;
        node2 = aux;
    }
    int root1 = first(dsu, node1);
    int root2 = first(dsu, node2);
    dsu[root2].second.splice(dsu[root2].second.end(), dsu[root1].second);
    dsu[root1].first = root2; 
}

int main(){

    int qtd_nodes, n1, n2, count;

    cin >> qtd_nodes;

    vector<pair<int, list<int>>> dsu(qtd_nodes);
    
    for (int i = 0; i < qtd_nodes; i++) {
        dsu[i].first = i;
        dsu[i].second.push_back(i);
    }

    for (int i = 0; i < qtd_nodes - 1; i++) {
        cin >> n1 >> n2;
        addEdge(dsu, n1 - 1, n2 - 1);
    }

    count = 0;
    for (int elemento : dsu[first(dsu, 0)].second) {
        count++;
        cout << elemento + 1;
        if (count == qtd_nodes) cout << "\n";
        else cout << " ";
    }

    return 0;
}