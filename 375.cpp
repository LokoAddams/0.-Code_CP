#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >>  n;
    string s;
    cin >> s;
    int cont = 0;
    for (int i = 0; i < int(s.size())-2; i++)
    {
        if(s[i] == '#' and s[i+1] == '.' and s[i+2] == '#')
            cont++;
    }
    
    cout << cont << endl;
    return 0;
}
