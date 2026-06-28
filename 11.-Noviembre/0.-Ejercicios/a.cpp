#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n; 
  map<int, int> m;
  while (n--)
  {
    int aux; cin >> aux;
    m[aux]++;
  }

  // Inicializamos mini con un valor muy grande
  int mini = INT_MAX; 
  queue<int> equipos_activos; // Guardará en qué número empezó cada equipo activo
  
  // Usamos el primer elemento - 1 para que el primer ciclo sea "consecutivo" por defecto
  int ant_val = m.begin()->first - 1; 

  for(auto [valor, frec]: m)
  {
    // 1. Si se rompe la racha consecutiva, TODOS los equipos activos se cierran
    if(valor != ant_val + 1)
    {
      while(!equipos_activos.empty())
      {
        int inicio = equipos_activos.front();
        equipos_activos.pop();
        // El tamaño del equipo es (el último valor válido - donde inició + 1)
        mini = min(mini, ant_val - inicio + 1); 
      }
    }
    
    // 2. Si la frecuencia bajó, cerramos los equipos sobrantes (los más antiguos)
    while(equipos_activos.size() > frec)
    {
      int inicio = equipos_activos.front();
      equipos_activos.pop();
      mini = min(mini, ant_val - inicio + 1); 
    }
    
    // 3. Si la frecuencia subió (o acabamos de vaciar la cola), nacen nuevos equipos
    while(equipos_activos.size() < frec)
    {
      equipos_activos.push(valor); // El equipo nace en el 'valor' actual
    }
    
    ant_val = valor;
  }

  // 4. Al terminar de recorrer el mapa, cerramos cualquier equipo que haya quedado abierto
  while(!equipos_activos.empty())
  {
    int inicio = equipos_activos.front();
    equipos_activos.pop();
    mini = min(mini, ant_val - inicio + 1);
  }

  cout << mini << endl;
  return 0;
}