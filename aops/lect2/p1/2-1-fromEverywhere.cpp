#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN=750;

ll dist[mxN+1][mxN+1];

int main(){
    // freopen("2-1.in", "r", stdin);
    memset(dist, INF, sizeof(dist));
    int n, m, u, v, c; cin>>n>>m;
    for(int i = 1; i<=n; i++){
        dist[i][i]=0;
    }
    for(int i = 1; i<=m; i++){
        cin>>u>>v>>c;
        dist[u][v]=c;
    }
    for(int x = 1; x<=n; x++){
        for(int a = 1; a<=n; a++){
            for(int b = 1; b<=n; b++){
                dist[a][b]=min(dist[a][b], dist[a][x]+dist[x][b]);
            }
        }
    }
    ll ans=0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            // cout<<i<<","<<j<<": "<<dist[i][j]<<" | ";
            ans+=dist[i][j];
        }
        // cout<<'\n';
    }
    cout<<ans;
}