#include <bits/stdc++.h>
using namespace std;
#define form(i,s,e) for(int i = s; i < e; i++)
vector<int> ans(int(1e9+1));
int dp(int n)
{
    if(ans[n] != 0) return ans[n];

    int m = int(1e9);
    for(int i = n-1; i >= 0; i--)
        m = min(m, 1+dp(i));
    return ans[n] = m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ans[2] = 2;
    ans[1] = 1;
    int cont = 0 ;
    for(int i = 2; i*(i-1)/2 <= int(1e9); i++)
        ans[i*(i-1)/2] = 1, cont++;
    cout << cont << endl;
    return 0;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp(n)<< endl;
    }

    return 0;
}
