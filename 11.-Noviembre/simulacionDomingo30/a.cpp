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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  icin(nn0)
  while (nn0--) {
    icin(n)
    scin(s1)scin(s2)
    vector<string> m;
    m.pb(s1);m.pb(s2);
    
    
    int i = 0, j= 0;
    string ans;
    int cont = 0;
    while (j < n)
    {
      ans.pb(m[i][j]);
      char r = '9', d = '9';
      if(i+1 < 2)
        d = m[i+1][j];
      if(j+1 < n)
        r = m[i][j+1];
      if(r <= d)
        j++;
      else
      {
        i++;
        for(int j2 = j; j2 >= 1; j2--)
          if(m[0][j2] == m[1][j2-1]) cont++;
          else break;
      }
    }
    cout << ans << endl;
    cout << 1 + cont << endl;
  }

  return 0;
}
