#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> paralelos;
vector<char> ans;
void bc(int materia){
  if(materia >= paralelos.size()) {
    // Si llegamos aquí, LA COMBINACIÓN YA ES 100% VÁLIDA (SIN CRUCES)
    // Aquí puedes calcular el puntaje de la fórmula y guardarlo.
    return;
  }
  
  for(auto e: paralelos[materia]) {
    // --- LA PODA ---
    // ¿El paralelo 'e' tiene un cruce de horario con lo que ya está en 'ans'?
    if(tieneCruceHorario(ans, e)) {
        continue; // Descartamos esta rama completa inmediatamente
    }

    ans.push_back(e);
    bc(materia+1);
    ans.pop_back();
  }
}

int main()
{
  int materias, num_paralelos; cin >> materias >> num_paralelos;
  paralelos.assign(materias, vector<char> ());
  for (int i = 0; i < num_paralelos; i++)
  {
    int materia; cin >> materia;
    char paralelo; cin >> paralelo;
    paralelos[materia].push_back(paralelo);
  }

  bc(0);
  
  return 0;
}