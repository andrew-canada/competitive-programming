#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN=1e5;

vector<int>adjL1[mxN+1], adjL2[mxN+1];
bool vis[mxN+1];
stack<int> stk;

void dfs1(int u){
    vis[u]=true;
    for(int v:adjL1[u]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    stk.push(u);
}

void dfs2(int u){
    vis[u]=true;
    for(int v:adjL2[u]){
        if(!vis[v]){
            dfs2(v);
        }
    }
}

int main(){
    // freopen("2-2.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v, ans=0; cin>>n>>m;
    for(int i = 0; i<m; i++){
        cin>>u>>v;
        --u, --v;
        adjL1[u].pb(v);
        adjL2[v].pb(u);
    }
    for(int u = 0; u<n; u++){
        if(!vis[u]){
            dfs1(u);
        }
    }
    memset(vis, 0, sizeof(vis));
    while(!stk.empty()){
        if(!vis[stk.top()]){
            dfs2(stk.top());
            ++ans;
        }
        stk.pop();
    }
    cout<<ans;
}