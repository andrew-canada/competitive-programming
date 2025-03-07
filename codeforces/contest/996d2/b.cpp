#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

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
        bool ok = true;
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
                needArr.pb(b[i] - a[i]);
            }
            else
            {
                have += (a[i] - b[i]);
                minHave = min(minHave, a[i] - b[i]);
            }
        }
        if (minHave < need)
        {
            ok = false;
        }
        else
        {
            ll curNeed = need;
            sort(needArr.begin(), needArr.end());
            for (int i = 1; i < needArr.size(); i++)
            {
                if (needArr[i] - curNeed < 0)
                {
                    ok = false;
                    break;
                }
                curNeed -= needArr[i - 1];
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}