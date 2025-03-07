#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e5, mxQ = 3e5;

int a[mxN + 1];
map<int, int> freq;
array<int, 3> queries[mxQ + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    int last = 0;
    for (int i = 0; i < q; ++i)
    {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        if (type == 1)
        {
            int p = ((x + last) % n) + 1;
            int newVal = ((y + last) % n) + 1;
            a[p - 1] = newVal;
        }
        else if (type == 2)
        {
            int l = ((x + last) % n) + 1;
            int r = ((y + last) % n) + 1;
            if (l > r)
            {
                swap(l, r);
            }
            --l;
            --r;

            freq.clear();
            for (int j = l; j <= r; ++j)
            {
                freq[a[j]]++;
            }

            int totPairs = (r - l + 1) * (r - l) / 2;
            int samePairs = 0;
            for (auto &p : freq)
            {
                samePairs += p.second * (p.second - 1) / 2;
            }

            int ans = totPairs - samePairs;
            cout << ans << " ";
            last = ans;
        }
    }
    cout << "\n";
}