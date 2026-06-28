#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 100005; // Ajustar según el problema

vector<int> adj[MAXN];

// Estructuras de datos para Tarjan
int tin[MAXN];       // Tiempo de descubrimiento (Time In)
int low[MAXN];       // El nodo más antiguo alcanzable (Low-Link)
bool on_stack[MAXN]; // Saber si un nodo está actualmente en la pila
stack<int> st;       // Pila para guardar la componente actual

int timer = 0;       // Reloj global
vector<vector<int>> sccs; // Aquí guardaremos las componentes finales

void dfs(int u) {
    // 1. Inicializar el nodo al descubrirlo
    timer++;
    tin[u] = timer;
    low[u] = timer;
    
    st.push(u);
    on_stack[u] = true;

    // 2. Explorar los vecinos
    for (int vecino : adj[u]) {
        if (tin[vecino] == 0) {
            // Caso A: El vecino NO ha sido visitado
            dfs(vecino);
            // Al regresar del vecino, actualizamos nuestro low-link
            low[u] = min(low[u], low[vecino]);
        } 
        else if (on_stack[vecino]) {
            // Caso B: El vecino ya fue visitado y está en nuestra pila
            // Esto significa que encontramos una arista de retroceso (back-edge)
            low[u] = min(low[u], tin[vecino]);
        }
        // Nota: Si el vecino ya fue visitado pero NO está en la pila, 
        // significa que pertenece a una SCC que ya cerramos. Lo ignoramos.
    }

    // 3. Evaluar si somos la raíz de una Componente Fuertemente Conexa
    if (low[u] == tin[u]) {
        vector<int> current_scc;
        int sacado;
        
        // Vaciamos la pila hasta sacar al nodo 'u'
        do {
            sacado = st.top();
            st.pop();
            on_stack[sacado] = false; // Ya no está en la pila
            current_scc.push_back(sacado);
        } while (sacado != u);
        
        // Guardamos la componente completa
        sccs.push_back(current_scc);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Como el grafo puede estar desconectado, lanzamos Tarjan 
    // desde cualquier nodo que no haya sido visitado.
    for (int i = 1; i <= n; i++) {
        if (tin[i] == 0) {
            dfs(i);
        }
    }

    // Imprimir resultados
    cout << "Se encontraron " << sccs.size() << " componentes fuertemente conexas.\n";
    for (int i = 0; i < sccs.size(); i++) {
        cout << "SCC " << i + 1 << ": ";
        for (int nodo : sccs[i]) {
            cout << nodo << " ";
        }
        cout << "\n";
    }

    return 0;
}