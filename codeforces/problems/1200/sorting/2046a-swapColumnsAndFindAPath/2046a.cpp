#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int sum = 0, ans = -INF;
        for (int i = 0; i < n; i++)
        {
            sum += max(a[i], b[i]);
        }
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, sum + min(a[i], b[i]));
        }
        cout << ans << '\n';
    }
}