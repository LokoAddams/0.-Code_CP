#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10005;
const long long INF = 1e18; // Un infinito suficientemente grande

// Matriz de distancias: dist[nodo][0 para PAR, 1 para IMPAR]
long long dist[MAX_N][2];
vector<pair<int, long long>> g[MAX_N];

// 1. Limpieza de memoria para Casos de Prueba Múltiples (UVa style)
void reset_tc(int n) {
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}

// 2. Estructura para el Dijkstra de Estados
struct State {
    int u;
    int parity;
    long long cost;
    
    // Regla de Oro: Solo usar '>' para armar el Min-Heap en C++
    bool operator>(const State& other) const {
        return cost > other.cost; 
    }
};

void solve(int n, int m) {
    reset_tc(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w}); // Es un grafo bidireccional
    }

    // Inicializamos todas las distancias en Infinito
    for (int i = 0; i <= n; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    // Cola de prioridad que ordena de menor a mayor costo usando 'greater'
    priority_queue<State, vector<State>, greater<State>> pq;

    // Nodo inicial: Ciudad 1. Hemos dado 0 pasos, así que la paridad es 0 (Par).
    dist[1][0] = 0;
    pq.push({1, 0, 0});

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        int u = curr.u;
        int p = curr.parity;
        long long d = curr.cost;

        // Optimización crucial: Si encontramos un camino más viejo y peor en la cola, lo ignoramos
        if (d > dist[u][p]) continue;

        // Explorar vecinos
        for (auto edge : g[u]) {
            int v = edge.first;
            long long w = edge.second;
            
            // Si estaba en PAR, paso a IMPAR. Si estaba en IMPAR, paso a PAR.
            int next_p = 1 - p; 

            // Relajación de Dijkstra
            if (dist[v][next_p] > d + w) {
                dist[v][next_p] = d + w;
                pq.push({v, next_p, dist[v][next_p]});
            }
        }
    }

    // El resultado es llegar al nodo N con paridad PAR (0)
    if (dist[n][0] == INF) {
        cout << "-1\n";
    } else {
        cout << dist[n][0] << "\n";
    }
}

int main() {
    
    int n, m;
    // Lectura continua hasta que no haya más casos de prueba (EOF)
    while (cin >> n >> m) {
        solve(n, m);
    }
    
    return 0;
}