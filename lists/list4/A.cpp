#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int qtd_clients, current_clients, max_clients, i, j;
    int *clients_in, *clients_out;

    cin >> qtd_clients;

    clients_in = new int[qtd_clients];
    clients_out = new int[qtd_clients];

    i = 0;
    j = 0;
    for (int k = 0; k < qtd_clients; k++) {
        cin >> clients_in[i++];
        cin >> clients_out[j++];
    }

    sort(clients_in, clients_in + qtd_clients);
    sort(clients_out, clients_out + qtd_clients);

    max_clients = 0;
    current_clients = 0;
    i = 0;
    j = 0;
    while (i < qtd_clients && j < qtd_clients) {
        if (clients_in[i] <= clients_out[j]){
            current_clients++;
            i++;
        }
        else {
            current_clients--;
            j++;
        }
        if (current_clients > max_clients)
            max_clients = current_clients;
    }

    cout << max_clients << "\n";

    delete [] clients_in;
    delete [] clients_out;
    return 0;
}
