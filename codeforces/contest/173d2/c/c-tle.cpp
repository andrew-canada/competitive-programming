#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int a[mxN + 1], psa[mxN + 1];
set<int> sums;

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
            psa[i + 1] = psa[i] + a[i];
        }

        sums.clear();
        sums.insert(0);
        for (int i = 0; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                sums.insert(psa[j] - psa[i]);
            }
        }

        cout << sums.size() << '\n';
        for (int i : sums)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}