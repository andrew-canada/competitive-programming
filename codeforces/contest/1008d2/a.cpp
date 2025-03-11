#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, x, sum = 0;
    cin >> n >> x;
    vector<int> a(n);
    bool hasX = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum == x * n)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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