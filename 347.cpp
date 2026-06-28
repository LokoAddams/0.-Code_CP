#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, a,  b;
    cin >> n >> a >> b;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    int l = vec[0];
    bool f = true;
    for (int i = 1; i < n; i++)
    {
        if(vec[i] - l >= a)
        {
            l = vec[i];
            int diff = (vec[i] - vec[i-1]) % (a+b);
            if(!(diff > b or diff == 0))
                f =  false;
        }
    }
    if(f) cout << "Yes"<< endl;
    else cout   << "No" <<endl;

    return 0;
}

