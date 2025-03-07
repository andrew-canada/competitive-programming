#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, ans;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 2)
    {
        cout << min(a[0], a[1]) << '\n';
        return;
    }
    ans = min(a[0], a[1]);
    for (int i = 0; i < n - 2; i++)
    {
        vector<int> temp;
        for (int k = 0; k <= 2; k++)
        {
            temp.push_back(a[i + k]);
        }
        sort(temp.begin(), temp.end());
        ans = max(ans, temp[1]);
    }
    cout << ans << '\n';
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
