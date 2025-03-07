#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f

void solve()
{
    int n, j = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            j = i + 1;
        }
    }
    if (j == 0)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < j; i++)
    {
        int minA = min(a[i], a[i + 1]);
        a[i] -= minA, a[i + 1] -= minA;
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");
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