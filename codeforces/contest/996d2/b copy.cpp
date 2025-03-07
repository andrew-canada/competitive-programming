#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n), b(n), needArr;
        ll need = 0, have = 0, minHave = INF;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] > a[i])
            {
                need += (b[i] - a[i]);
            }
            else
            {
                have += (a[i] - b[i]);
                minHave = min(minHave, a[i] - b[i]);
            }
        }
        cout << (have >= need * (n - 1) ? "YES\n" : "NO\n");
    }
}