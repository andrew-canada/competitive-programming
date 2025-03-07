#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

const int INF = int(1e9);

int h, n;
vector<int> p;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> h >> n;
        p.resize(n);
        fore(i, 0, n)
                cin >>
            p[i];

        int ans = 0;

        int lf = 0;
        fore(i, 0, n)
        {
            if (i > 0 && p[i - 1] > p[i] + 1)
            {
                if (lf > 0)
                    ans += (i - lf) & 1;
                else
                    ans += 1 - ((i - lf) & 1);
                lf = i;
            }
        }
        if (p[n - 1] > 1)
        {
            if (lf != 0)
                ans += (n - lf) & 1;
            else
                ans += 1 - ((n - lf) & 1);
        }

        cout << ans << endl;
    }
    return 0;
}