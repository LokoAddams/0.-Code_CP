#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Usamos un infinito lo suficientemente grande, pero que al sumarle algo 
// no cause un overflow (desbordamiento) en los enteros.
const long long INF = 1e18;

int main() {
    // Optimizaciones de E/S
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 1. Inicialización de la Matriz
    // Creamos una matriz NxN llena de "Infinito"
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    // La distancia de un nodo hacia sí mismo es siempre 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // 2. Lectura de las aristas (Grafo Dirigido)
    for (int i = 0; i < m; i++) {
        int u, v;
        long long peso;
        cin >> u >> v >> peso;
        
        // CUIDADO: Si el problema tiene múltiples aristas conectando el mismo 
        // par de nodos (multigrafo), siempre debes guardar la más barata.
        dist[u][v] = min(dist[u][v], peso); 
    }

    // 3. El Algoritmo de Floyd-Warshall (La magia de la DP)
    // K: Es el nodo intermedio (pivote) que estamos intentando usar
    for (int k = 1; k <= n; k++) {
        // I: Es el nodo de origen
        for (int i = 1; i <= n; i++) {
            // J: Es el nodo de destino
            for (int j = 1; j <= n; j++) {
                
                // Si puedo llegar de I->K y de K->J, verifico si esa combinación
                // es más barata que el camino directo que ya tenía de I->J.
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
                
            }
        }
    }

    // 4. Detección de Ciclos Negativos con Floyd-Warshall
    // Si la distancia de un nodo hacia sí mismo se volvió menor a 0, 
    // significa que forma parte de un ciclo negativo.
    bool tiene_ciclo_negativo = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) {
            tiene_ciclo_negativo = true;
            break;
        }
    }

    // 5. Imprimir los resultados
    if (tiene_ciclo_negativo) {
        cout << "El grafo tiene un ciclo de peso negativo.\n";
    } else {
        cout << "Matriz de distancias minimas:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] == INF) cout << "INF ";
                else cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}