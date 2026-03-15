#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int find_set(vector<int> &parents, int node) {
    if (parents[node] == node)
        return node;
    return parents[node] = find_set(parents, parents[node]);
}

bool unite(vector<int> &parents, vector<int> &rank, int n1, int n2) {
    int root1 = find_set(parents, n1);
    int root2 = find_set(parents, n2);

    if (root1 != root2) {
        if (rank[root1] < rank[root2])
            swap(root1, root2);
        parents[root2] = root1;
        if (rank[root1] == rank[root2])
            rank[root1]++;
        return true; 
    }
    return false; 
}

struct Edge {
    int u, v, id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries;
    cin >> queries;

    while (queries--) {
        int n;
        cin >> n;

        vector<int> dsu(2 * n + 1);
        vector<int> rank(2 * n + 1, 0);
        for (int i = 0; i <= 2 * n; i++) dsu[i] = i;

        vector<Edge> edges(n);
        for (int i = 0; i < n; i++) {
            cin >> edges[i].u >> edges[i].v;
            edges[i].id = i + 1;
        }
        
        vector<int> escolhidos;
        for (int i = 0; i < n; i++) {
            if (unite(dsu, rank, edges[i].u, edges[i].v)) {
                escolhidos.push_back(edges[i].id);
            }
        }

        cout << escolhidos.size() << "\n";
        for (int i = 0; i < escolhidos.size(); i++) {
            cout << escolhidos[i] << (i == escolhidos.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}