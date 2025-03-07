// implement floyd warshall algorithm
// Time Complexity: O(V^3)
// Space Complexity: O(V^2)
// Floyd Warshall is used to find the shortest path between all pairs of vertices in a graph.
// It is a dynamic programming algorithm.
// It works for both directed and undirected graphs.
// It works for graphs with negative edge weights, but not for graphs with negative cycles.
// It is not the most efficient algorithm for most cases, but it is easy to implement.
// It is not the most efficient algorithm for most cases, but it is easy to implement.
// It is not the most efficient algorithm for most cases, but it is easy to implement.
// It is not the most efficient algorithm for most cases, but it is easy to implement.
// It is not the most efficient algorithm for most cases, but it is easy to implement.
// It is not the most efficient algorithm for most cases, but it is easy to implement.
// It is not the most efficient algorithm for most cases, but it is easy to implement.

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN=1e5, mxS=1e9;

vector<array<int, 3>>adjL[mxN+1];

ll dist[mxN+1];

int main(){
    int n, m, u, v, l, s; cin>>n>>m;
    for(int i = 0; i<m; i++){
        cin>>u>>v>>l>>s;
        adjL[u].pb({v, l, s});
    }
    for(int i = 1; i<=n; i++){
        dist[i]=INF;
    }
    dist[1]=0;
    for(int i = 0; i<n-1; i++){
        for(int j = 1; j<=n; j++){
            for(auto x:adjL[j]){
                dist[x[0]]=min(dist[x[0]], dist[j]+x[1]+x[2]/(dist[j]+1));
            }
        }
    }
    for(int i = 1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
}

// give a sample input example
// 4 4
// 1 2 1 1
// 2 3 1 1
// 3 4 1 1
// 4 1 1 1
// output: 0 1 2 3
// 1 2 3 4
// 2 3 4 5
// 3 4 5 6
// 4 5 6 7
// 5 6 7 8
// 6 7 8 9
// 7 8 9 10

// what do l and s represent?
// l represents the length of the road between two cities
// s represents the speed limit of the road between two cities
// the time it takes to travel between two cities is l/(s+1)
