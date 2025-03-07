#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX_N 524288
int stree[MAX_N * 2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int sz = 1;
    while (sz < n)
    {
        sz <<= 1;
    }
    for (int i = 0; i < (2 * sz - 1); ++i)
    {
        stree[i] = 0;
    }
    ll total = 0;
    int nxt;
    for (int i = 0; i < n; ++i)
    {
        cin >> nxt;
        nxt--;
        int chunk = sz / 2;
        int tree_idx = 0;
        int subtotal = 0;
        while (chunk >= 0)
        {
            stree[tree_idx]++;
            if (chunk == 0)
            {
                break;
            }
            if (nxt >= chunk)
            {
                nxt -= chunk;
                subtotal += stree[2 * tree_idx + 1]; // fold in the whole left branch
                tree_idx = 2 * tree_idx + 2;
            }
            else
            {
                tree_idx = 2 * tree_idx + 1;
            }
            chunk /= 2;
        }
        total += subtotal;
    }
    cout << total << '\n';
}