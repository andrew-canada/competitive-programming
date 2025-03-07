#include <bits/stdc++.h>
using namespace std;
int vis[200000];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    long long n, k, i;
    for (cin >> T; T > 0; T--)
    {
        cin >> n >> k;
        if (n < 50 && (1LL << (n - 1)) < k)
        {
            cout << "-1\n";
            continue;
        }
        k--;
        for (i = n - 1; i > 0; i--)
        {
            if (k & 1)
                vis[i] = 0;
            else
                vis[i] = 1;
            k /= 2;
        }
        for (i = 1; i < n; i++)
        {
            if (vis[i])
                cout << i << ' ';
        }
        cout << n << ' ';
        for (i = n - 1; i > 0; i--)
        {
            if (!vis[i])
                cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}