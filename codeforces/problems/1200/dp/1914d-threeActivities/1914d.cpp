#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

array<int, 3> top3(const vector<int> &arr)
{
    int mx1 = -1, mx2 = -1, mx3 = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mx1 == -1 || arr[i] > arr[mx1])
        {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        }
        else if (mx2 == -1 || arr[i] > arr[mx2])
        {
            mx3 = mx2;
            mx2 = i;
        }
        else if (mx3 == -1 || arr[i] > arr[mx3])
        {
            mx3 = i;
        }
    }
    return {mx1, mx2, mx3};
}

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    array<int, 3> bestA = top3(a), bestB = top3(b), bestC = top3(c);
    for (int x : bestA)
    {
        for (int y : bestB)
        {
            for (int z : bestC)
            {
                if (x != y && x != z && y != z)
                {
                    ans = max(ans, a[x] + b[y] + c[z]);
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