#include <bits/stdc++.h>

using namespace std;

const int mxN = 200;

int a[mxN + 1], b[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }

    int ans = (1 << 10) - 1;

    for (int cur = 0; cur < (1 << 10); ++cur)
    {
        bool valid = true;
        for (int i = 0; i < n && valid; ++i)
        {
            bool found = false;
            for (int j = 0; j < m; ++j)
            {
                if (((a[i] & b[j]) | cur) == cur)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                valid = false;
            }
        }
        if (valid)
        {
            ans = cur;
            break;
        }
    }

    cout << ans << '\n';
}