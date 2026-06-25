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
    icin(n)
    scin(s)
    ll fa, la, fb, lb;
    fa = la = fb = lb = 0;
    string aux = s;
    s.clear();
    ll cont_rep = 1;
    vi w;
    s.pb(aux[0]);
    form (i,1,n) {
      if(aux[i] != s.back())
      {
        s.pb(aux[i]);
        w.pb(cont_rep);
        cont_rep = 1;
      }
      else
      {
        cont_rep ++;
      }
    }
    w.pb(cont_rep);
    
    ll wfa = 0;
    form(i,0,n)
    {
      if(s[i] == 'a')
      {
        fa= i;
        wfa = w[i];
        break;
      }
    }
    for (ll i = n-1; i >= 0; i--)
    {
      if(s[i] == 'a')
      {
        la= i;
        break;
      }
    }
    
    ll ant_a = fa, w_ant_a = wfa;
    ll da = 0 ;
    form(i,fa+1,la+1)
    {
      if(s[i] == 'a')
      {
        da += ((i- ant_a - 1)* min(w_ant_a , w[i]));
        ant_a = i;
        w_ant_a = w[i];
      }
    }

    /////
    ll wfb = 0;
    form(i,0,n)
    {
      if(s[i] == 'b')
      {
        fb= i;
        wfb = w[i];
        break;
      }
    }

    for (ll i = n-1; i >= 0; i--)
    {
      if(s[i] == 'b')
      {
        lb= i;
        break;
      }
    }
    
    ll ant_b = fb, w_ant_b = wfb;
    ll db = 0;
    form(i,fb+1,lb+1)
    {
      if(s[i] == 'b')
      {
        db += ((i- ant_b - 1)* min(w[i], w_ant_b));
        w_ant_b = w[i];
        ant_b = i;
      }
    }
    if(fa == la )
    {
      if(fa != fb)
      cout << min(w[fb] * w[fa], (n - (w[fb] + w[fa])) * w[fa]) << endl;
      else
      {
        cout << 0 << endl;
      }
      
      continue;
    }
    if(fb == lb)
    {
      if(fa != fb)
      cout << min(w[fb] * w[fa], (n - (w[fb] + w[fa])) * w[fb]) << endl;
      else
      {
        cout << 0 << endl;
      }
      continue;
    }
    cout << min(da,db) << endl;
  }

  return 0;
}
