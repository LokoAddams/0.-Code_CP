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
  deque<int> d1, d2 ;
  icin(nn0)
  while (nn0--) {
    scin(s)icin(num)
    int n = d1.size() + d2.size() ;
    if(s == "push_back")
    {
      d2.push_back(num);
      if(d2.size() == d1.size() + 2)
      {
        d1.pb(d2.front());
        d2.pop_front();
      }
    }else
    {
      if(s == "push_front")
      {
        d1.push_front(num);
        if(d1.size() == d2.size() + 2)
        {
          d2.push_front(d1.back());
          d1.pop_back();
        }
      }
      else
      {
        if(s == "push_middle")
        {
          int m = (n + 1)/2;
          if(d1.size() == d2.size())
          {
            d1.push_back(num);
          }
          else
          {
            if(m == d1.size()) 
            {
              d2.push_front(num);
            }
            else
            {
              int aux = d2.front(); 
              d2.pop_front();
  
              d1.push_back(aux);
              d2.push_front(num);
            }

          }
          
        }
        else
        {
          if(num < d1.size())
          {
            cout << d1[num] << endl;
          }
          else
          {
            num -= d1.size();
            cout << d2[num] << endl;
          }
          
        }
        
      }
      
    }
    
  }

  return 0;
}
