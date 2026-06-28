#include <bits/stdc++.h>
using namespace std;
#define int long long

int n =  (int)(1e5+1);
int MOD = (int)(1e9+7);
vector<vector<pair<int,int>>> mat(n,vector<pair<int,int>>());
vector<int> dist(n, (int)(1e18)), caminos(n), mini(n), maxi(n);

void dj(int u)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,  greater<pair<int,int>>> q;
    q.push({0, u});
    caminos[u] = 1;
    dist[u] = 0;
    while (!q.empty())
    {
        auto [d, nodo] = q.top();
        q.pop();
        
        if(d > dist[nodo]) continue;

        for(auto [vecino, d2]: mat[nodo])
        {
            if(d + d2 < dist[vecino])
            {
                caminos[vecino] = caminos[nodo];
                mini[vecino] = mini[nodo]+1;
                maxi[vecino] = maxi[nodo]+1;
                dist[vecino] = d + d2;
                q.push({d + d2, vecino});
            }
            else
            {
                if(d + d2 == dist[vecino])
                {
                    caminos[vecino] = (caminos[vecino] + caminos[nodo])% MOD;
                    mini[vecino] = min(mini[vecino] , mini[nodo]+1);
                    maxi[vecino] = max(maxi[vecino], maxi[nodo]+1);
                }
            }
        }
    }
}


signed main(){
    cin >> n;
    int  m; cin >>  m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        mat[a].push_back({b,c});
    }
    dj(1);
    cout << dist[n] <<" "<< 
    caminos[n] << " "<< 
    mini[n] << " "<< maxi[n] << endl;
    return 0;
}