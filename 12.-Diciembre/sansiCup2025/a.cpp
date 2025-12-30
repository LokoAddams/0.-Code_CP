#include <bits/stdc++.h>
using namespace std;
#define form(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'

int n;

vector<vector<int>> adj((int)1e5+1);
vector<char> vis((int)1e5+1, 'n');
int timer = 0; vector<int> in((int)1e5+1),out((int)1e5+1);
vector<int> contador((int)1e5+1);

struct Node
{
  vector<pair<int,int>> top5;
  Node(){}
  Node(int node){
    top5.push_back({0,node});
  }
  Node(pair<int,int> nuevo){
    top5.push_back(nuevo);
  }
};


vector<int> A;
template<typename T>
struct SegmentTree {
    int n;
    vector<T> tree;
    T neutro = T();

    SegmentTree(int sz) {
        n = sz;
        tree.assign(4 * n, neutro);
    }

    T merge(T a, T b) {
      vector<pair<int,int>>& l = a.top5, r = b.top5;
      if(l.empty()) return b;
      if(r.empty()) return a;

      l.insert(l.end(), r.begin(), r.end());
      sort(l.begin(), l.end(), greater<pair<int,int>> ());
      map<int,int> mp;
      vector<pair<int,int>> ans;
      for (auto &&[f,nodo] : l)
      {
        if(!mp.count(nodo))
          ans.push_back({f,nodo});
      }
      
      if(ans.size() > 5)
        ans.resize(5);
      Node aux;
      aux.top5 = ans;
      return aux;
    }

    void update(int p, T value) {
      for (tree[p += n] = value; p > 1; p >>= 1)
          tree[p >> 1] = merge(tree[p], tree[p ^ 1]);
    }

    T query(int l, int r) {
      T res = neutro;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
          if (l & 1) res = merge(res, tree[l++]);
          if (r & 1) res = merge(res, tree[--r]);
      }
      return res;
    }
};


void dfs(int u)
{
  A.push_back(u);
  in[u] = timer;
  timer++;

  vis[u] = 'v';

  for (auto &&v : adj[u])
  {
    if(vis[v] == 'n')
      dfs(v);
  }
  out[u] = timer;  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n;
  form(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1);
  SegmentTree<Node> st((int)A.size());
  for (int i = 0; i < int(A.size()); i++)
    st.update(i,Node(A[i]));


  int q; cin >> q;
  form(i,0,q)
  {
    int o; cin >> o;
    if(o == 1)
    {
      int v,x;cin >> v >> x;
      contador[v] += x;
      st.update(in[v],Node(pair<int,int>(contador[v],v)));
    }
    else
    {
      int v; cin >> v;
      vector<pair<int,int>> ans = st.query(in[v], out[v]).top5;
      for (auto &&[f,nodo] : ans)
        cout << f << " ";
      if(ans.size() < 5)
        form(i,0,5-ans.size()) cout << ans[ans.size()-1].first << " ";
      cout << endl;
    }
    
  }

  return 0;
}