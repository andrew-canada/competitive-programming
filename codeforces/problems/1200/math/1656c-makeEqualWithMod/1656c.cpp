#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool one = 0, consec = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            one = 1;
        }
        if (i < n - 1 && a[i] + 1 == a[i + 1])
        {
            consec = 1;
        }
    }
    cout << (one && consec ? "NO\n" : "YES\n");
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