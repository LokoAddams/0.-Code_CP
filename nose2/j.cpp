#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
  int q; cin >> q;
  while(q--){
    int n, k; cin >> n >> k;
    int mult = 2;
    int par = 0;
    if(n%2 != 0)par = 1;
    if(k%2 == 0) 
    {
      cout << k/2 << endl;
      continue;
    }
    
    
    cout << k*mult << endl;
  }

  return 0;
}