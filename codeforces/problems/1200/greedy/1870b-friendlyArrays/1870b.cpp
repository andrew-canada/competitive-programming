#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int minSum = 0, maxSum = 0, total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxSum ^= a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        total |= b[i];
    }
    for (int i = 0; i < n; i++)
    {
        minSum ^= a[i] | total;
    }
    if (minSum > maxSum)
    {
        swap(maxSum, minSum);
    }
    cout << minSum << " " << maxSum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}