#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;  int m;
    cin >> n >> m;
    vector<bool> f(n+1);
    for (int i = 0; i < m; i++)
    {
        int a; char b;
        cin >> a >> b;
        if(b == 'M')
            if(f[a] == false)
            {
                cout << "Yes" << endl;
                f[a] = true;
                continue;
            }
        cout << "No" << endl;
    }
    
    return 0;
}
