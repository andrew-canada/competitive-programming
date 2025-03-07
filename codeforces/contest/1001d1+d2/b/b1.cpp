#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

int t, n;

bool solve()
{
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<int> cur(n + 1);
    for (int start = 1; start <= n; start++)
    {
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            cur[i] = arr[i];
        }
        cur[1] -= start - 1;
        for (int i = 2; i <= start; i++)
        {
            cur[i] -= i - 2;
        }
        for (int i = start + 1; i <= n; i++)
        {
            cur[i] -= start - 1;
        }
        for (int i = 1; i <= (n + 1) / 2; i++)
        {
            if (cur[i] <= 2 * n - i || cur[n - i + 1] <= 2 * n - i)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}