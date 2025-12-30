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
    icin(c)icin(m)icin(x)
    ll mini = min(c,min(m,x));
    c -= mini, m-= mini, x-= mini;
    if(c == 0 or m == 0)
    {
      cout << mini << endl;
    }
    else
    {
      ll maxi = max(c,m);
      ll mini2 = min(c,m);
      if( c >= 2*m or m >= 2*c)
      {
        cout << mini + mini2 << endl;
      }
      else
      {
        ll cont = 0;
        cout << mini + (mini2 + maxi)/3  << endl;
      }
      
    }
    
  }

  return 0;
}
