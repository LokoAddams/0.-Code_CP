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
const double EPS = 1e-7;
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




int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  icin(nn0)
  while (nn0--) {
    icin(n)icin(k)
    scin(s)
    int espacio = 0;
    ll ans = 0;
    int start = 0;
    //ceros al inicio
    for(start = 0;start<n;start++)
    {
      if(s[start] == '0') espacio++;
      else
      {
        if(espacio > k)
            ans += (espacio/(k+1));
        break;
      }
    }
    //solo ceros
    if(start == n)
    {
      if(espacio <= k+1)
      cout << 1 << endl;
      else
      cout << (n-1)/(k+1)+1 << endl;
      continue;
    }
    espacio = 0;
    // 1001
    form(i,start,n)
    {
      if(s[i] == '0') espacio++;
      else
      {
        if(espacio > k*2)
          if(espacio%(k+1) == k)
            ans += (espacio/(k+1));
          else
            ans += ((espacio/(k+1))-1);
        espacio = 0;
      }
    }
    // 1000
    if(espacio > k)
      ans += (espacio/(k+1));
    cout << ans << endl;
  }

  return 0;
}
