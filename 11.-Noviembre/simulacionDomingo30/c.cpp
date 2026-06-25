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
    icin(r)
    ll r2 = r*r;
    double r2_limite = (r+1)*(r+1)-0.1;
    ll s = ceil(sqrt(r2+r2));
    ll ans = 0;
    for (ll k = s; k >= 0; k--)
    {
      ll cont = 0, k2 = k*k,aum = 0;
      ll x1 = sqrt(r2-k2), x2 = sqrt(r2_limite-k2);
      if(sqrt(r2-k2) - x1 <= 1e-9)
        aum = 1;
      if(x2>=x1 and x2>=0 and x1>=0)
        cont = x2-x1+aum;
      ans += cont;
    }
    cout << ans*4 - 4 << endl;
    
  }

  return 0;
}
