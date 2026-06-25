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

long long mat[101][101];
long long ncr(long long n, long long r)
{
  if(r == 0 or r == n) return 1;
  
  if(mat[n][r] != 0) 
    return mat[n][r];
  else
  {
    mat[n-1][r-1] = ncr(n-1,r-1);
    mat[n-1][r] = ncr(n-1,r);
    return mat[n-1][r-1] + mat[n-1][r];
  } 
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long n, k;
  while (cin >> n >> k)
  {
    if(n == 0 and k == 0) break; 
    cout << n << " things taken "<< k<<" at a time is " <<ncr(n,k)  <<" exactly."<< endl;
  }
  

  return 0;
}
