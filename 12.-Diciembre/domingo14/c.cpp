#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

#define form(i, s, e) for(int i = s; i < e; i++)
#define scin(x) string x; cin >> x;
#define icin(x) int x; cin >> x;
#define icin2(x, y) int x, y; cin >> x >> y;
#define llcin(x) ll x; cin >> x;
#define llcin2(x, y) ll x, y; cin >> x >> y;
#define DBG(x) cerr << #x << '=' << (x) << endl
#define RAYA cerr << '====================' << endl
#define pb push_back
#define len(x) (int)x.size()
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

const ll INF =  1e18;
const int MOD = 1e9 + 7;

/////////////////////// OPCIONALES ///////////////////////

typedef double db;
const db PI = acos(-1);
#define coutDouble(p) cout << fixed << setprecision(p)
#define numtobin(n) bitset<32>(n).to_string() 
#define bintoint(bin_str) stoi(bin_str, nullptr, 2)  // bin_str should be a STRING
#define LSOne(S) ((S) & -(S)) 
// Háganle r34 al Soruco por favor


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a ,b;
  while (true) {
    cin >> a >> b;
    if(a == "*" and b == "*")break;
    int cont = 0;
    form(i,0,a.size())
    {
      while(a[i] != b[i] and i < a.size())
      {
        i++;
        if(i == a.size() or a[i] == b[i])
          cont++;
      }
      
    }
    cout << cont << endl;
  }

  return 0;
}
