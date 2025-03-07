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
        vector<int> v(n + 1, -INF);
        int val;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        cin >> val;
        string ans = "YES\n";
        for (int i = 1; i < n; i++)
        {
            int sub = v[i] - val;
            if (v[i] <= v[i + 1])
            {
                if (sub >= v[i - 1])
                {
                    v[i] = sub, v[i + 1] -= val;
                }
                else if (v[i + 1] - val >= v[i])
                {
                    v[i + 1] -= val;
                }
                i++;
            }
            else if (v[i] > v[i + 1] && sub <= v[i + 1] && sub >= v[i - 1])
            {
                v[i] = sub;
            }
            else
            {
                ans = "NO\n";
                break;
            }
        }
        cout << ans;
    }
}