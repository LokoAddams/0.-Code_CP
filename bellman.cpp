#include <iostream>
#include <vector>

using namespace std;

// Usamos un infinito seguro para evitar desbordamientos (overflows) al sumar
const long long INF = 1e18; 

// Estructura súper simple para guardar las conexiones
struct Arista {
    int u, v;
    long long peso;
};

int main() {
    // Optimizaciones de entrada/salida
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Arista> aristas(m);
    for (int i = 0; i < m; i++) {
        cin >> aristas[i].u >> aristas[i].v >> aristas[i].peso;
    }

    int origen = 1; // Asumimos que queremos calcular desde el nodo 1

    // 1. Inicialización
    vector<long long> dist(n + 1, INF);
    dist[origen] = 0;

    // 2. Relajación de aristas (V - 1 veces)
    for (int i = 1; i <= n - 1; i++) {
        bool algun_cambio = false; // Bandera para optimización temprana
        
        for (const auto& arista : aristas) {
            // Regla de oro: Solo relajamos si ya logramos llegar al nodo de origen 'u'
            if (dist[arista.u] != INF && dist[arista.u] + arista.peso < dist[arista.v]) {
                dist[arista.v] = dist[arista.u] + arista.peso;
                algun_cambio = true;
            }
        }
        
        // OPTIMIZACIÓN: Si en una vuelta completa al mapa no mejoró ninguna distancia,
        // significa que ya encontramos todos los caminos mínimos. Podemos detenernos.
        if (!algun_cambio) break; 
    }

    // 3. Detección de Ciclos Negativos (La iteración número V)
    bool ciclo_negativo = false;
    for (const auto& arista : aristas) {
        if (dist[arista.u] != INF && dist[arista.u] + arista.peso < dist[arista.v]) {
            ciclo_negativo = true;
            break; // Con uno solo que mejore, ya sabemos que el grafo está roto
        }
    }

    // 4. Imprimir resultados
    if (ciclo_negativo) {
        cout << "Se detecto un ciclo de peso negativo en el grafo.\n";
    } else {
        cout << "Distancias minimas desde el nodo " << origen << ":\n";
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}