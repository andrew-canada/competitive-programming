#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] != a[1])
    {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] % a[0] != 0)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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