#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, k = 0, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        k += __builtin_ctz(a);
        v[i] = __builtin_ctz(i + 1);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int x : v)
    {
        if (k >= n)
        {
            break;
        }
        ans++;
        k += x;
    }
    cout << (k >= n ? ans : -1) << '\n';
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