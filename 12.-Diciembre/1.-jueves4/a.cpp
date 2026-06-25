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
    icin(n)icin(k)
    vi vec(n);
    form(i,0,n) cin >> vec[i];

    sort(all(vec));
    vector<ll> comp, frec;
    comp.pb(vec[0]);
    frec.pb(1);
    form(i,1,n){
      if(vec[i] != comp.back())
      {
        comp.pb(vec[i]);
        frec.pb(1);
      }
      else
        frec[frec.size() - 1]++;    
    }


    int l = 0, r = 0, ancho ;
    ll maxi = -1, ans;
    n = frec.size();
    while (r < n)
    {
      r++;
      ans = frec[l];
      ancho = 2;
      while (r < n and ancho <= k and comp[r] == comp[r-1]+1)
      {
        ans += frec[r];
        r++;
        ancho++;
      }
      r--;
      ancho --;
      maxi = max(maxi , ans);
      

      if(ancho == k)
      {
        r++;
        while (r < n and comp[r] == comp[r-1]+1)
        {
          ans -= frec[l];
          ans += frec[r];
          maxi = max(maxi , ans);
          r++;
          l++;
        }
        r--;
      }
      l = r = r + 1;
    }
    cout << maxi << endl;

  }

  return 0;
}
