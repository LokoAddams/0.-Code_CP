#include <bits/stdc++.h>
using namespace std;

//IMPRESINDIBLES PARA ICPC
#define form(i, s, e) for(ll i = s; i < e; i++)
#define icin(x)  \
  ll x;         \
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;

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
typedef pair<ll,bool> pib;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef vector<pll> vpll;




int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  icin(nn0)
  while (nn0--) {
    icin(n)icin(m)icin(k)icin(w)
    
    vector<ll> g(w);
    form(i,0,w)
      cin >> g[i];
    sort(all(g), greater<ll> ());

    vector<int> f(k*k+1);
    form(i,1,n+1)
      form(j,1,m+1)  
        f[min(i,min(k,min(i,k)-(k-1-(n-i))))*min(j,min(k,min(j,k)-(k-1-(m-j))))]++;
    
    ll ans = 0;
    for (int i = k*k, j = 0; i >= 0 and j < g.size(); i--)
    {
      if(f[i] != 0)
      {
        f[i]--;
        ans += (i*g[j]);
        i++;
        j++;
      }
    }
    
    cout << ans << endl;
    
  }

  return 0;
}
