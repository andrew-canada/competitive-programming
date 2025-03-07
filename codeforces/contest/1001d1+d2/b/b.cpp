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
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        if (arr[i] <= 2 * n - i || arr[n - i + 1] <= 2 * n - i)
        {
            return false;
        }
    }
    return true;
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