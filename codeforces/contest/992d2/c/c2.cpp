#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    ll k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> a, b;
        if (n <= 60 && 1ll << (n - 1) < k)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> num;
        --k;
        while (k)
        {
            num.pb(k % 2);
            k >>= 1;
        }
        while (num.size() < n - 1)
        {
            num.pb(0);
        }
        for (int i = n - 2, j = 1; i >= 0; i--, j++)
        {
            if (num[i])
            {
                b.pb(j);
            }
            else
            {
                a.pb(j);
            }
        }

        reverse(b.begin(), b.end());
        for (int i : a)
        {
            cout << i << " ";
        }
        cout << n << " ";
        for (int i : b)
        {
            cout << i << " ";
        }
        cout << '\n';
    }
}