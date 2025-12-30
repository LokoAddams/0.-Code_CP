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
#define bintoint(bin_str) stoi(bin_str, nullptr, 2)  // bin_str should be s STRING
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

  scin(s)
  char maxi , mini;
  if(s[1] == '>')
  {
    maxi = s[0];
    mini = s[2];
  }
  else
  {
    maxi = s[2];
    mini = s[0];
  }

  cin >> s;
  if(s[1] == '>')
  {
    if(s[2] == maxi)
    {
      maxi = s[0];
    }
    if( mini == maxi )
    {
      cin >> s;
      cout << "Impossible" << endl;
      return 0;
    }
    if(s[0] == mini)
    {
      mini = s[2];
    }
  }
  else
  {
    //<
    if(s[0] == maxi)
    {
      maxi = s[2];
    }
    if( mini == maxi )
    {
      cin >> s;
      cout << "Impossible" << endl;
      return 0;
    }
    if(s[2] == mini)
    {
      mini = s[0];
    }

  }

  
  cin >> s;
  if(s[1] == '>')
  {
    if(s[2] == maxi)
    {
      maxi = s[0];
    }
    if( mini == maxi )
    {
      cout << "Impossible" << endl;
      return 0;
    }
    if(s[0] == mini)
    {
      mini = s[2];
    }
  }
  else
  {
    //<
    if(s[0] == maxi)
    {
      maxi = s[2];
    }
    if( mini == maxi )
    {
      cout << "Impossible" << endl;
      return 0;
    }
    if(s[2] == mini)
    {
      mini = s[0];
    }

  }
  char medio = ' ';
  for(char i : string("ABC"))
  {
    if(i != maxi and i != mini)
    {
      medio = i;
    }
  }
  if(mini == medio or medio == maxi or maxi == mini)
  {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << mini << medio << maxi << endl;
  return 0;
}
