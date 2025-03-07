#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN=1e5;

vector<int>adjL[mxN+1];
bool vis[mxN+1], cycEnd;
int nCyc, inCyc, source, dfsStart, curCyc;

void dfs(int u){
    for(int v:adjL[u]){
        // cout<<v<<'\n';
        if(!vis[v]){
            vis[v]=true;
            dfs(v);
            if(v==source){
                cycEnd=true;
            }
            if(!cycEnd){
                ++curCyc;
            }
        }
        else{
            if(u!=dfsStart){
                source=v;
                ++curCyc;
            }
        }
    }
}

int main(){
    // freopen("2-2.in", "r", stdin);
    int n, m, u, v; cin>>n>>m;
    for(int i = 0; i<m; i++){
        cin>>u>>v;
        --u, --v;
        adjL[u].pb(v);
    }
    for(int a = 0; a<n; a++){
        if(!vis[a]){
            curCyc=0;
            cycEnd=false;
            dfsStart=a;
            vis[a]=true;
            dfs(a);
            if(curCyc>1){
                inCyc+=curCyc;
                ++nCyc;
            }
        }
    }
    cout<<n-inCyc+nCyc;
}