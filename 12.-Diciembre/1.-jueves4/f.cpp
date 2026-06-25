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
#define blloll(bin_str) stoi(bin_str, nullptr, 2)  // bin_str should be a STRING
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

  icin(t)
  while (t--)
  {
    icin(n)icin(k)
    vi vec(n);
    form(i,0,n)
      cin >> vec[i];

    sort(all(vec));
    
    ll maxi = 0, cont = 0, cont2 = 1;
    vi ans(k);
    ans[0]++;
    form(i,1,n)
    {
      if(vec[i] == vec[i-1])
      {
        ans[cont]++;
      }
      else
      {
        if(vec[i] == vec[i-1] + 1)
        {
          cont++;
          cont2++;
          if(cont2 > k)
          {
            cont = 0;
            cont2 --;
            ll res = 0;
            form(i,0,ans.size())
            res += ans[i];
            maxi = max(maxi , res);
            ans[0] = 0;
          }
          ans[cont] = 0;
          ans[cont]++;
        }
        else
        {
          ll res = 0;
          form(i,0,cont2)
            res += ans[i];
          maxi = max(maxi , res);
          ans.assign(k,0);
          cont = 0;
          cont2 = 1;
          ans[0]++; 
        }
        
      }
    }
    ll res = 0;
    form(i,0,cont2)
      res += ans[i];
    maxi = max(maxi , res);
    cout << maxi << endl;
  }
  return 0;
}
