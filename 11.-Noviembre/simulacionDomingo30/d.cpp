#include <bits/stdc++.h>
using namespace std;

//IMPRESINDIBLES PARA ICPC
#define form(i, s, e) for(int i = s; i < e; i++)
#define icin(x)  \
  int x;         \
  cin >> x;
#define llcin(x) \
  long long x;   \
  cin >> x;
#define scin(x)  \
string x;        \
cin >> x;
#define endl '\n'
#define S second
#define F first
#define pb push_back
#define sz(x) x.size()
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const ll INF =  1e9+7;//tambien es primo
const double PI = acos(-1);
//UTILES
#define DBG(x) cerr << #x << '=' << (x) << endl
#define coutDouble cout << fixed << setprecision(17)
#define numtobin(n) bitset<32>(n).to_string()
#define bintoint(bin_str) stoi(bin_str, nullptr, 2)  // bin_str should be a STRING
#define LSOne(S) ((S) & -(S))

typedef double db;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,bool> pib;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef vector<pll> vpll;

vector<ll> dist;
struct cmp
{
  bool operator()(const pair<int, ll>& a, const pair<int, ll>& b)
  {
    return a.second >b.second;
  }
};


void dij(int n, vector<vector<pair<int,ll>>> &adj, int src, priority_queue<pair<int,ll>, vector<pair<int,ll>>, cmp> q)
{
  dist.assign(2*n+1, -1);
  dist[src] = 0;
  q.push({src, 0});
  while (!q.empty())
  {
    auto u  = q.top();
    q.pop();
    if(u.second > dist[u.first])
    {
      continue;
    }
    for(auto v: adj[u.first])
    {
      if(dist[v.first] > dist[u.first] + v.second or dist[v.first] == -1)
      {
        dist[v.first] = dist[u.first] + v.second;
        q.push({v.first, dist[v.first]});
      }
    }
  }
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  while (cin >> n >> m)
  {
    int u, v;
    ll p;
    vector<vector<pair<int, long long >>> adj(2*n+1);
    priority_queue<pair<int,ll>, vector<pair<int,ll>>, cmp> q;
    form(i,0,m)
    {
      cin >> u >> v >> p;
      adj[u].pb({v+n,p});
      adj[v].pb({u+n,p});
      adj[u+n].pb({v,p});
      adj[v+n].pb({u,p});
    }
    dij(n,adj, 1,q);
    if(dist[n] != -1)
    {
      cout << dist[n] << endl;
    }
    else
    {
      cout << -1 << endl;
    }
    adj.clear();
  }
  
  
  return 0;
}
