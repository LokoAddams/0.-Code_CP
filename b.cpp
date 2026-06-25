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
    int origen = 1;
    vector<long long> dist(n + 1, INF);
    dist[origen] = 0;
    for (int i = 1; i <= n - 1; i++) {
        bool algun_cambio = false; // Bandera para optimización temprana
        for (const auto& arista : aristas) {
            if (dist[arista.u] != INF && dist[arista.u] + arista.peso < dist[arista.v]) {
                dist[arista.v] = dist[arista.u] + arista.peso;
                algun_cambio = true;
            }
        }
        if (!algun_cambio) break; 
    }
    bool ciclo_negativo = false;
    for (const auto& arista : aristas) {
        if (dist[arista.u] != INF && dist[arista.u] + arista.peso < dist[arista.v]) {
            ciclo_negativo = true;
            break; // Con uno solo que mejore, ya sabemos que el grafo está roto
        }
    }
}