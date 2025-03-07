#include <bits/stdc++.h>

using namespace std;

const int mxN = 200;

int a[mxN + 1];

bool stable(vector<int> &seg)
{
    int n = seg.size();
    if (n == 1)
    {
        return true;
    }
    if (n == 2)
    {
        return (2 * min(seg[0], seg[1]) > max(seg[0], seg[1]));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                int x = seg[i], y = seg[j], z = seg[k];
                if (x + y <= z || y + z <= x || z + x <= y)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool solve(vector<int> &arr, bool found)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        vector<int> left(arr.begin(), arr.begin() + i);
        vector<int> right(arr.begin() + i, arr.end());
        if (stable(left))
        {
            if (stable(right) && (found || i > 1 || n - i > 1))
            {
                return true;
            }
            else
            {
                if (solve(right, i > 1 || found))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 2)
        {
            cout << (2 * min(a[0], a[1]) > max(a[0], a[1]) ? "YES\n" : "NO\n");
            continue;
        }

        vector<int> arr(a, a + n);
        if (solve(arr, false))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}