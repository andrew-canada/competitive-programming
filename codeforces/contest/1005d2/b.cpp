#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), freq(n + 1), len(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    len[0] = freq[a[0]] == 1;
    for (int i = 1; i < n; i++)
    {
        if (freq[a[i]] == 1)
        {
            len[i] = len[i - 1] + 1;
        }
    }
    int val = *max_element(len.begin(), len.end());
    if (val == 0)
    {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (len[i] == val)
        {
            cout << i - len[i] + 2 << " " << i + 1 << "\n";
            return;
        }
    }
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