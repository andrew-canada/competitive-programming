#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = n - 1, minVal = 1, maxVal = n;
    while (l <= r)
    {
        if (a[l] == minVal)
        {
            l++;
            minVal++;
        }
        else if (a[l] == maxVal)
        {
            l++;
            maxVal--;
        }
        else if (a[r] == minVal)
        {
            r--;
            minVal++;
        }
        else if (a[r] == maxVal)
        {
            r--;
            maxVal--;
        }
        else
        {
            break;
        }
    }
    if (l <= r)
    {
        cout << l + 1 << " " << r + 1 << '\n';
        return;
    }
    cout << "-1\n";
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
