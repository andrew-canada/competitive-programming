#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX_N 750
// This value stands in for infinity in our Floyd-Warshall matrix. It is HUUGE with an extra U because there is
// already a system macro called HUGE. This is perhaps a bit sloppy / silly!
#define HUUGE 1000000000000

ll floyd[MAX_N][MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      floyd[i][j] = ((i == j) ? 0 : HUUGE);
    }
  }
  int a, b;
  ll c;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    a--;
    b--;
    floyd[a][b] = c;
  }
  // Make sure k is on the outside of this loop, or you will get a wrong answer!
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
      }
    }
  }
  ll total = 0;
  // We don't explicitly rule out the "diagonal" cells where i = j, but since it is guaranteed that there are
  // no negative cycles in this graph, all of these will have values of 0 anyway.  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      total += floyd[i][j];
    }
  }
  cout << total << '\n';
}