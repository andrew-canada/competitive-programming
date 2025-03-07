#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000
#define MAX_D 9
#define INF (MAX_N * MAX_D + 1)

vector<int> adj[MAX_N + 1] = {};

// For K=2:
// dp[x][j][i] = lowest sum for subtree rooted at i where
// i is given digit j and i's children do not include the label x
// (which means i's parent is allowed to have label x)
int dpK2[MAX_D + 1][MAX_D + 1][MAX_N + 1] = {};

// For K=1:
// dp[j][i] = lowest sum for subtree rooted at i where
// i is given digit j. Since we're allocating dpK2 anyway, just use
// dpK2[0] for this.
auto dpK1 = dpK2[0];

// given an element and a vector, find the element in the vector and remove it
// from the vector
vector<int> removeElement(int e, vector<int> v)
{
    vector<int> ans = {};
    for (int i : v)
    {
        if (i != e)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, d, k;
    cin >> n >> d >> k;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Toposort the tree. In the k=2 case, the root is the only node which
    // could have d-2 children; our later DP assumes this is not the case
    // so here we instead find a leaf to be the root
    int root = 1;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1)
        {
            root = i;
            break;
        }
    }
    vector<int> topo;
    stack<int> x;
    x.push(root);
    while (!x.empty())
    {
        int u = x.top();
        x.pop();
        topo.push_back(u);
        for (int v : adj[u])
        {
            adj[v] = removeElement(u, adj[v]);
            x.push(v);
        }
    }
    reverse(topo.begin(), topo.end());

    if (k == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= d; j++)
            {
                dpK1[j][i] = INF;
            }
        }

        for (int v : topo)
        {
            for (int j = 1; j <= d; j++)
            {
                int sum = j;
                for (int u : adj[v])
                {
                    int bestSubtree = INF;
                    for (int q = 1; q <= d; q++)
                    {
                        if (q != j)
                        {
                            bestSubtree = min(bestSubtree, dpK1[q][u]);
                        }
                    }
                    sum += bestSubtree;
                }
                dpK1[j][v] = sum;
            }
        }

        int ans = INF;
        for (int j = 1; j <= d; j++)
        {
            ans = min(ans, dpK1[j][root]);
        }

        cout << ans << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= d; j++)
            {
                for (int q = 1; q <= d; q++)
                {
                    dpK2[q][j][i] = INF;
                }
            }
        }

        for (int v : topo)
        {
            for (int j = 1; j <= d; j++)
            {
                int subDP[1 << d] = {};
                for (int mask = 0; mask < (1 << d); mask++)
                {
                    subDP[mask] = INF;
                }
                // subDP[mask] = lowest sum for subtree rooted at v where
                // v is given digit j and v with its children have labels given by
                // the bits set in mask (offset by 1, e.g. bit 3 means digit 4)
                // Note that at least half the space in subDP is never used since
                // all our masks will have at least bit (j-1) set, so we could
                // compress this but we don't need to
                subDP[1 << (j - 1)] = j;
                for (int uIdx = 0; uIdx < adj[v].size(); uIdx++)
                {
                    int u = adj[v][uIdx];
                    for (int mask = 0; mask < (1 << d); mask++)
                    {
                        if (__builtin_popcount(mask) == uIdx + 1)
                        {
                            for (int q = 1; q <= d; q++)
                            {
                                if (!(mask & (1 << (q - 1))))
                                {
                                    int newMask = mask | (1 << (q - 1));
                                    subDP[newMask] = min(subDP[newMask], subDP[mask] + dpK2[j][q][u]);
                                }
                            }
                        }
                    }
                }
                for (int mask = 0; mask < (1 << d); mask++)
                {
                    if (__builtin_popcount(mask) == adj[v].size() + 1)
                    {
                        for (int b = 1; b <= d; b++)
                        {
                            if (!(mask & (1 << (b - 1))))
                            {
                                dpK2[b][j][v] = min(dpK2[b][j][v], subDP[mask]);
                            }
                        }
                    }
                }
            }
        }

        int ans = INF;
        for (int j = 1; j <= d; j++)
        {
            for (int b = 1; b <= d; b++)
            {
                ans = min(ans, dpK2[b][j][root]);
            }
        }

        cout << ans << endl;
        return 0;
    }
}