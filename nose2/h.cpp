#include <bits/stdc++.h>
using namespace std;
#define int long long
#define form(i, s, e) for(int i = s; i < e; i++)

//temporal O(n) espacial(1)

signed main()
{
  int t;
  cin >> t;
  while(t--){
    int n,mini = 100,maxi = -1;cin >> n;
    
    form(i,0,n)
    {
      int aux;cin >> aux;
      mini = min(aux,mini);
      maxi = max(aux,maxi);
    }
    cout << (maxi - mini)*2 << endl;
  }
  
  return 0;
}