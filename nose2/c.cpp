#include <bits/stdc++.h>
using namespace std;
#define int long long

int m,k,n;
vector<pair<int,int>> vec(2e5);
set<int> col;
signed main()
{
  cin >> n >> k >> m;
  for(int i = 0; i < n; i++)
  {
    int c, v;
    cin >> c >> v;
    vec[i] = {v,c};
  }
  sort(vec.begin(), vec.end(), greater<pair<int,int>> ());

  int sum = 0;
  vector<int> restantes;
  for(auto [v,c]: vec)
  {
    if(m != 0 and col.insert(c).second)
    {
      m--;
      sum += v;
      k--;
    }
    else
    {
      restantes.push_back(v);
    }
  }
  if(k != 0)
  {
    for(auto elem: restantes)
    {
      k--;
      sum += elem;
      if(k == 0) break;
    }
  }
  cout << sum << endl;
  return 0;
}