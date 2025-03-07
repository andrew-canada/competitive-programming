#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

typedef struct {vector<int> out; vector<int> in; int component; bool visited;} vdata;
typedef int node;

// graph[0] is unused
vdata graph[MAX_N+1] = {};
vector<node> l;
int totalComponents = 0;

void visit(node u) {
  if (!graph[u].visited) {
    graph[u].visited = true;
    for (node v : graph[u].out) {
      visit(v);
    }
    l.push_back(u);
  }
}

void assign(node u, node c) {
  if (graph[u].component == 0) {
    graph[u].component = c;
    if (u == c) {
      totalComponents++;
    }
    for (node v : graph[u].in) {
      assign(v, c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // read input
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    node u, v;
    cin >> u >> v;
    graph[u].out.push_back(v);
    graph[v].in.push_back(u);
  }

  // Kosaraju's algorithm
  for (node u = 1; u <= n; u++) {
    visit(u);
  }
  for (auto it = l.rbegin(); it != l.rend(); it++) {
    node u = *it;
    assign(u,u);
  }

  cout << totalComponents << endl;

  return 0;
}