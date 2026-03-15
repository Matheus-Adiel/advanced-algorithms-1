#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries, qtd_pontos, x, y;
    long long int total_triangulos_rentangulos;
    cin >> queries;

    while (queries--) {
        cin >> qtd_pontos;

        vector<bool> tem_chao(qtd_pontos + 1, false);
        vector<bool> tem_teto(qtd_pontos + 1, false);
        total_triangulos_rentangulos = 0;

        for (int i = 0; i < qtd_pontos; i++) {
            cin >> x >> y;
            if (y == 0) tem_chao[x] = true;
            else tem_teto[x]  = true;
        }

        for (int x = 0; x <= qtd_pontos; x++) {
            if (tem_chao[x] && tem_teto[x]) total_triangulos_rentangulos += qtd_pontos - 2;
            if (x > 0 && x < qtd_pontos) {
                if(tem_chao[x - 1] && tem_teto[x] && tem_chao[x + 1]) total_triangulos_rentangulos++;
                if(tem_teto[x - 1] && tem_chao[x] && tem_teto[x + 1]) total_triangulos_rentangulos++;
            }
        }

        cout << total_triangulos_rentangulos << "\n";
    }

    return 0;
}