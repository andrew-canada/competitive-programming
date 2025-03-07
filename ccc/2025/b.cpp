#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    ll idx, curN, len = 0;
    string s, curS = "";
    cin >> s >> idx;
    vector<ll> lens;
    vector<char> chars;
    chars.pb(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        char c = s[i];
        if (c >= '0' && c <= '9')
        {
            curS += c;
            if (i == s.size() - 1)
            {
                curN = stoll(curS);
                lens.pb(curN);
                len += curN;
                curS = "";
            }
        }
        else
        {
            chars.pb(c);
            curN = stoll(curS);
            lens.pb(curN);
            len += curN;
            curS = "";
        }
    }
    idx %= len;
    ll pref = 0;
    for (int i = 0; i < lens.size(); i++)
    {
        ll l = lens[i];
        pref += l;
        if (idx < pref)
        {
            cout << chars[i] << '\n';
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}