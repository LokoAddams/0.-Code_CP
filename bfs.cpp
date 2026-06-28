#include <bits/stdc++.h>
using namespace std;

int n =  int(1e5+1); 
vector<vector<int>> mat(n,vector<int>());
vector<bool> vis(n);

int bfs(int u)
{
    int res = 0;
    queue<pair<int,int>> q;
    q.push({u,0});
    vis[u] = true;
    while (!q.empty())
    {
        auto [nodo, cont] = q.front();
        q.pop();
        if(cont + 1 != 3)
        {
            for(auto vecino: mat[nodo])
                if(vis[vecino] == false)
                    q.push({vecino, cont+1}), vis[vecino] =  true;
        }
        res++;
    }
    return res;
}


int main(){
    cin >> n;
    int  m; cin >>  m;
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        mat[a].push_back(b);
    }
    int maxi = -1;
    for(int i = 1; i <= n; i++)
        maxi  = max(maxi, bfs(i)), vis.assign(n,false);
    cout << maxi << endl;
    return 0;
}