#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1, -INF), b(n);
        int val;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        string ans = "YES\n";
        for (int i = 1; i < n; i++)
        {
            int sub = val - a[i];
            if (sub < a[i])
            {
                if (sub >= a[i - 1])
                {
                    a[i] = sub;
                }
            }
            else if (a[i] < a[i - 1])
            {
                a[i] = sub;
            }
        }
        a[n] = max(a[n], val - a[n]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[i + 1])
            {
                ans = "NO\n";
                break;
            }
        }
        cout << ans;
    }
}