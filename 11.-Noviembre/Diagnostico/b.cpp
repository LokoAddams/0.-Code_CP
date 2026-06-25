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

  icin(n)
  vi s(n), unos(n), ceros(n);
  form(i,0,n) cin >> s[i];
  
  if(s[0] == 1) unos[0]++;
  form(i,1,n)
    if(s[i] == 1) 
      unos[i] = unos[i-1]+1;

  if(s[n-1] == 0) ceros[n-1]++;
  for (int i = n-1 - 1; i >= 0; i--)
    if(s[i] == 0)
      ceros[i] = ceros[i+1]+1;
  
  int cont = 0;
  form(i,0,n-1)
    if(s[i] == 1 and s[i+1] == 0)
    {
      if(unos[i] <= ceros[i+1])
      {
        cont += unos[i];
      }
      else
      {
        cont += ceros[i+1];
        if(i+ceros[i+1]+1 < n)
        {
          unos[i+ceros[i+1]+1] += unos[i]; 
          i += (ceros[i+1]+1);
        }
      }
    }

  cout << n-cont << endl;
  return 0;
}
