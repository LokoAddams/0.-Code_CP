#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  int t, a, b,c;
  cin >> t;
  while(t--)
  {
    cin >> a >> b >> c;
    int n = b*c, d = c+b;
    while(__gcd(n,d) != 1)
    {
      int aux = __gcd(n,d);
      n /= aux;
      d /= aux;
    }
    cout << n << " " << d << endl;
  }
  return 0;
}