#include <bits/stdc++.h>
using namespace std;
#define int long long
//temporal O(n) espacial(1)

vector<int> vec;
signed main()
{
  int n;cin >> n;
  vec.resize(n);
  for(int i = 0; i < n; i++)
    cin >> vec[i];
  int cont =0;
  for(int i = 1; i < n; i++)
    if(vec[i] - vec[i-1] < 0)
    {
      cont += (-(vec[i] - vec[i-1]));
      vec[i] += (-(vec[i] - vec[i-1]));
    }
  cout << cont << endl;
  return 0;
}