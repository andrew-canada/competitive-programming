#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, ans = INF, cur, rem;
    cin >> n;
    for (int one = 0; one <= 2; one++)
    {
        for (int three = 0; three <= 1; three++)
        {
            for (int six = 0; six <= 4; six++)
            {
                for (int ten = 0; ten <= 2; ten++)
                {
                    cur = one + 3 * three + 6 * six + 10 * ten;
                    rem = n - cur;
                    if (cur <= n && rem % 15 == 0)
                    {
                        ans = min(ans, one + three + six + ten + rem / 15);
                    }
                }
            }
        }
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
