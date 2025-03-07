#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    long long sum = 0;
    for (int i = -1; i < n; i++)
    {
        long long now = sum;
        for (int j = i + 1; j < min(n, i + 32); j++)
        {
            int copy = a[j];
            copy >>= j - i;
            now += copy;
        }
        ans = max(ans, now);
        if (i + 1 != n)
        {
            sum += a[i + 1] - k;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}