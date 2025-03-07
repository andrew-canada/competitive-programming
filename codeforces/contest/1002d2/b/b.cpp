#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n >> k;
        vector<int> a(n);
        int rem = n - k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<vector<int>> p1(k + 1);
        for (int i = 0; i < 1 + rem; i++)
        {
            p1[0].push_back(a[i]);
        }
        int idx = 1;
        for (int i = 1 + rem; i < n; i++)
        {
            p1[idx].push_back(a[i]);
            idx++;
        }
        vector<int> r1;
        for (int i = 1; i < k; i += 2)
        {
            for (int j : p1[i])
            {
                r1.push_back(j);
            }
        }
        r1.push_back(0);
        for (int i = 0; i < r1.size(); i++)
        {
            if (r1[i] != i + 1)
            {
                ans = i + 1;
                break;
            }
        }

        vector<vector<int>> p2(k + 1);
        p2[0].push_back(a[0]);
        for (int i = 1; i <= 1 + rem; i++)
        {
            p2[1].push_back(a[i]);
        }
        idx = 2;
        for (int i = 2 + rem; i < n; i++)
        {
            p2[idx].push_back(a[i]);
            idx++;
        }
        vector<int> r2;
        for (int i = 1; i < k; i += 2)
        {
            for (int j : p2[i])
            {
                r2.push_back(j);
            }
        }
        r2.push_back(0);
        for (int i = 0; i < r2.size(); i++)
        {
            if (r2[i] != i + 1)
            {
                ans = min(ans, i + 1);
                break;
            }
        }
        cout << ans << '\n';
    }
}