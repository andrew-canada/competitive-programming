#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

int a[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] != 1 && a[i] != -1)
            {
                idx = i;
            }
        }
        int prefPos = 0, prefNeg = 0, curPos = 0, curNeg = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == idx)
            {
                curPos = 0, curNeg = 0;
                continue;
            }
            curPos += a[i], curNeg += a[i];
            curPos = (curPos < 0 ? 0 : curPos);
            curNeg = (curNeg > 0 ? 0 : curNeg);
            prefPos = max(prefPos, curPos);
            prefNeg = min(prefNeg, curNeg);
        }

        int sufMax = 0, sufMin = 0, cur = 0;
        for (int i = idx - 1; i >= 0; i--)
        {
            cur += a[i];
            sufMax = max(sufMax, cur);
            sufMin = min(sufMin, cur);
        }
        int prefMax = 0, prefMin = 0;
        cur = 0;
        for (int i = idx + 1; i < n; i++)
        {
            cur += a[i];
            prefMax = max(prefMax, cur);
            prefMin = min(prefMin, cur);
        }

        int maxVal = a[idx] + sufMax + prefMax, minVal = a[idx] + sufMin + prefMin;
        vector<int> ans;
        if (prefMin > maxVal)
        {
            for (int i = minVal; i <= maxVal; i++)
            {
                ans.pb(i);
            }
            for (int i = prefNeg; i <= prefPos; i++)
            {
                ans.pb(i);
            }
        }
        else if (prefPos < minVal)
        {
            for (int i = prefNeg; i <= prefPos; i++)
            {
                ans.pb(i);
            }
            for (int i = minVal; i <= maxVal; i++)
            {
                ans.pb(i);
            }
        }
        else
        {
            minVal = min(minVal, prefNeg), maxVal = max(maxVal, prefPos);
            for (int i = minVal; i <= maxVal; i++)
            {
                ans.pb(i);
            }
        }
        cout << ans.size() << '\n';
        for (int i : ans)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}