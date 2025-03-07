#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int n;
    bool ok = true;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        ok &= a[i] > max(i, n - i - 1) * 2;
    }
    return ok;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}