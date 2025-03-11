#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    if (k % 2)
    {
        a[n] = n - 1;
        for (int i = 1; i <= n - 1; i++)
        {
            a[i] = n;
        }
    }
    else
    {
        a[n - 1] = n;
        for (int i = 1; i < n - 1; i++)
        {
            a[i] = n - 1;
        }
        a[n] = n - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
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