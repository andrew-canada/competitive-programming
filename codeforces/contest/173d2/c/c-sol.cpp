#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 1 || a[i] < -1)
                p = i;
        }
        int l0 = 0, r0 = 0;
        int curpos = 0, curneg = 0;
        for (int i = 0; i < p; i++)
        {
            curpos += a[i];
            if (curpos < 0)
                curpos = 0;
            curneg += a[i];
            if (curneg > 0)
                curneg = 0;
            l0 = min(l0, curneg);
            r0 = max(r0, curpos);
        }
        curpos = 0, curneg = 0;
        for (int i = p + 1; i < n; i++)
        {
            curpos += a[i];
            if (curpos < 0)
                curpos = 0;
            curneg += a[i];
            if (curneg > 0)
                curneg = 0;
            l0 = min(l0, curneg);
            r0 = max(r0, curpos);
        }
        int l1 = 0, r1 = 0;
        int cur = 0;
        for (int i = p - 1; i >= 0; i--)
        {
            cur += a[i];
            l1 = min(l1, cur);
            r1 = max(r1, cur);
        }
        int l2 = 0, r2 = 0;
        cur = 0;
        for (int i = p + 1; i < n; i++)
        {
            cur += a[i];
            l2 = min(l2, cur);
            r2 = max(r2, cur);
        }
        int l = a[p] + l1 + l2;
        int r = a[p] + r1 + r2;
        vector<int> ans;
        if (r < l0)
        {
            for (int i = l; i <= r; i++)
                ans.emplace_back(i);
            for (int i = l0; i <= r0; i++)
                ans.emplace_back(i);
        }
        else if (r0 < l)
        {
            for (int i = l0; i <= r0; i++)
                ans.emplace_back(i);
            for (int i = l; i <= r; i++)
                ans.emplace_back(i);
        }
        else
        {
            l = min(l, l0);
            r = max(r, r0);
            for (int i = l; i <= r; i++)
                ans.emplace_back(i);
        }
        cout << ans.size() << '\n';
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}