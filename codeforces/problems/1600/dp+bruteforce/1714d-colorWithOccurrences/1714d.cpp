#include <bits/stdc++.h>

using namespace std;

const int mxN = 10;

int q, n, ans;
bool found;
string t;
string s[mxN + 1];
vector<array<int, 2>> match;

void solve(int a, int b)
{
    int longest = 0, idx = -1, pos = -1;
    for (int i = a; i <= b; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string cur = s[j];
            if (i + cur.size() > t.size() || i + cur.size() <= b)
            {
                continue;
            }
            if (t.substr(i, cur.size()) == cur && i + cur.size() > longest)
            {
                longest = i + cur.size();
                idx = j;
                pos = i;
            }
        }
    }
    if (idx == -1)
    {
        found = false;
        return;
    }
    else
    {
        match.push_back({idx, pos});
        ans++;
        if (longest == t.size())
        {
            return;
        }
        else
        {
            solve(max(b + 1, pos + 1), longest);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--)
    {
        ans = 0;
        found = true;
        cin >> t >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        match.clear();
        solve(0, 0);
        if (found)
        {
            cout << ans << '\n';
            for (const array<int, 2> &m : match)
            {
                cout << m[0] + 1 << ' ' << m[1] + 1 << '\n';
            }
        }
        else
        {
            cout << "-1\n";
        }
    }
}