#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, p[mxN + 1], sz[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(sz + 1, sz + n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 2; i <= n; i++)
    {
        sz[p[i]] = 0;
    }
    for (int i = n; i >= 1; i--)
    {
        sz[p[i]] += sz[i];
    }
    sort(sz + 1, sz + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << sz[i] << " ";
    }
}