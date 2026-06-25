#include <bits/stdc++.h>
using namespace std;
#define int long long
#define form(i, s, e) for(int i = s; i < e; i++)
#define icin(x)  \
  int x;         \
  cin >> x;
const int nax = (int)(1e5)+1;
  int m, n;
typedef vector<int> vi;
#define all(x) x.begin(),x.end()
#define endl '\n'

// temporal O(V+E) espacial O(V+E)

  vi g[nax+1], ts;
  bool seen[nax+1];
  void dfs(int u){
    seen[u] = true;
    for(int v: g[u])
    if (!seen[v])
    dfs(v);
    ts.push_back(u);
  }
  void topo(int n){
    form(i,1,n+1) if (!seen[i]) dfs(i);
    reverse(all(ts));
  }
vector<char> state(nax+1);

  bool dfs_detect_cycle(int node)
{
    if(state[node] == 'b')
        return true;
    if (state[node] == 'c') return false;
    state[node] = 'b';
    for(auto i: g[node])
    {
        if(dfs_detect_cycle(i))
        {
            return true;
        }
    }
    state[node] = 'c';
    return false;
}
  
  signed main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
  form(i,0,m)
  {
    icin(a)icin(b)
    g[a].push_back(b);
  }
    form(i,0,nax+1) state[i] = 'a';

  form(i,1,n+1)
  {
    if(state[i] == 'a')
    {
      if(dfs_detect_cycle(i))
      {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }

  topo(n);
  for(auto e: ts){
    cout << e << " ";
  }
  cout << endl;

  return 0;
}