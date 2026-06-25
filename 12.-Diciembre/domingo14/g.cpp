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

void resolver(int n) {
  bool ss, sq,spq;
  ss = sq = spq = true;
  stack<int> s;
  queue<int> q;
  priority_queue<int> pq;
  form(i,0,n)
  {
    icin(a)icin(b)
    if(a == 1)
    {
      s.push(b);
      q.push(b);
      pq.push(b);
    }
    else
    {
      int so = -1, qo = -1, pqo = -1;
      if(!s.empty())
      {
        so = s.top();
        s.pop();
      }
      if(!q.empty())
      {
        qo = q.front();q.pop();
      }
      if(!pq.empty())
      {
        pqo = pq.top();pq.pop();
      }

      if(so != b) ss = false;
      if(qo != b) sq = false;
      if(pqo!= b) spq = false;
    }
  }
  int cont = 0;
  if(ss == true)cont++;
  if(sq == true)cont++;
  if(spq == true)cont++;
  if(cont > 1)
  {
    cout << "not sure" << endl;
  }
  else
  {
    if(cont == 0)
    cout << "impossible" << endl;
    else
    {
      if(ss)
      cout << "stack" << endl;
      if(sq)
      cout << "queue" << endl;
      if(spq)
      cout << "priority queue" << endl;
    }
  }
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  while (cin >> n) {
    resolver(n);
  }

  return 0;
}
