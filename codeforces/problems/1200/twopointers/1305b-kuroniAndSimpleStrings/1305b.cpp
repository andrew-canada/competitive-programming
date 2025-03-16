#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> left, right;
    int l = 0, r = n - 1;
    while (l < r)
    {
        while (l < n && s[l] == ')')
        {
            l++;
        }
        while (r >= 0 && s[r] == '(')
        {
            r--;
        }
        if (l < n && r >= 0 && l < r)
        {
            left.pb(l + 1);
            right.pb(r + 1);
            l++;
            r--;
        }
    }
    if (left.empty())
    {
        cout << "0\n";
        return;
    }
    cout << "1\n";
    cout << 2 * left.size() << '\n';
    for (int x : left)
    {
        cout << x << " ";
    }
    reverse(right.begin(), right.end());
    for (int x : right)
    {
        cout << x << " ";
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
}