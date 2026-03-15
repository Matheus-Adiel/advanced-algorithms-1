#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int parent(vector<int> &parents, int node) {
    if (parents[node] == node)
        return node;
    int aux = parent(parents, parents[node]);
    parents[node] = aux;
    return aux; 
}

int parentDistance(vector<int> &parents, int node) {
    int distance = 0;
    while (parents[node] != node) {
        distance++;
        node = parents[node];
    }
    return distance;
}

void addEdge(vector<int> &parents, int node1, int node2) {
    int aux;
    if (parentDistance(parents, node1) > parentDistance(parents, node2)) {
        aux = node1;
        node1 = node2;
        node2 = aux;
    }
    parents[parent(parents, node1)] = parent(parents, node2);
}

int inSameComponent(vector<int> &parents, int node1, int node2) {
    if (parent(parents, node1) == parent(parents, node2))
        return 1;
    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_nodes, qtd_edges, node1, node2, cust, count_edges = 0;
    long long int cust_total = 0;

    cin >> qtd_nodes >> qtd_edges;

    vector<int> dsu(qtd_nodes);
    vector<pair<int, pair<int, int>>> edges(qtd_edges);

    for (int i = 0; i < qtd_nodes; i++)
        dsu[i] = i;

    for (int i = 0; i < qtd_edges; i++) {
        cin >> node1 >> node2 >> cust;
        edges[i] = make_pair(cust, make_pair(node1 - 1, node2 - 1));
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < qtd_edges; i++) {
        if (!inSameComponent(dsu, edges[i].second.first, edges[i].second.second)) {
            addEdge(dsu, edges[i].second.first, edges[i].second.second);
            cust_total += edges[i].first;
            count_edges++;
        }
    }

    if (count_edges == qtd_nodes - 1)
        cout << cust_total;
    else
        cout << "IMPOSSIBLE";
    cout << "\n";

    return 0;

}