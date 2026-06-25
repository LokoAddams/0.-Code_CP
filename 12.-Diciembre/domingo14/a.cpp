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

struct query{
  int l, r,w, time;
};

class Node{
  public:
  int val = -1;
  int time = int(3e5);
};

class SegmentTree{
  private:
  int n;
  vector<Node> A,st,lazy;
  int l(int p) { return p<<1;}
  int r(int p) { return (p<<1)+1;}

  Node conquer(Node a, Node b){
    if(a.val == -1) return b;
    if(b.val == -1) return a;
    return (b.time < a.time)? b: a;
  }
  void build(int p , int L , int R)
  {
    if(L == R)
    st[p] = A[L];
    else{
      int m = (L+R)/2;
      build(l(p), L,m);
      build(r(p), m+1,R);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

  void propagate(int p, int L , int R)
  {
    if(lazy[p].val != -1)
    {
      st[p] = lazy[p];
    if(L != R)
      lazy[l(p)] = lazy[r(p)] = lazy[p];
    else
      A[L] = lazy[p];
    lazy[p].val = -1;
    }
  }
  void update(int p, int L , int R , int i , int j , Node val){
    propagate(p,L,R);
    if(i > j) return;
    if((L >= i) and (R <= j)){
      lazy[p] = val;
      propagate(p,L,R);
    }
    else
    {
      int m = (L+R)/2;
      update(l(p), L,m,i,min(m,j), val);
      update(r(p), m+1,R,max(i,m+1),j,val);

      Node lsubtree = (lazy[l(p)].val != -1)? lazy[l(p)]:st[l(p)];
      Node rsubtree = (lazy[r(p)].val != -1)? lazy[r(p)]:st[r(p)];
      
      st[p] = conquer(lsubtree,rsubtree);
    }
  }

  Node RMQ(int p, int L, int R, int i, int j)
  {
    propagate(p,L,R);
    if(i > j) return Node();
    if((L>=i) and (R <= j)) return st[p];
    int m = (L+R)/2;
    Node left = RMQ(l(p), L, m, i, min(m,j));
    Node right = RMQ(r(p), m+1, R, max(i,m+1),j);
    return conquer(left, right);
  }
  
  public:
  SegmentTree(int sz):n(sz),A(n),st(4*n),lazy(4*n){}
  SegmentTree(const vector<Node> &initialA): SegmentTree((int)initialA.size()){
    A = initialA;
    build(1,0,n-1);
  }
  void update(int i, int j, Node val){
    update(1,0,n-1,i,j,val);
  }
  Node RMQ(int i, int j){ return RMQ(1,0,n-1,i,j);}
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  icin(n)icin(m)
  vector<query> q;
  form(i,0,m)
  {
    icin(l)icin(r)icin(w)
    query aux;
    aux.l = l; aux.r = r; aux.w = w;aux.time = i;
    q.pb(aux);
  }
  reverse(ALL(q));
  Node aux2;
  vector<Node> ini(n,aux2);
  SegmentTree stt(ini);
  form(i,0,m)
  {
    Node aux;
    aux.val = q[i].w-1;
    aux.time = q[i].time;
    stt.update(q[i].l-1,q[i].w-2,aux);
    stt.update(q[i].w,q[i].r-1,aux);

  }
  form(i,0,n)
  {
    cout << stt.RMQ(i,i).val + 1 << " ";
  }
  cout << endl;

  return 0;
}
