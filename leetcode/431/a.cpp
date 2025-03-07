#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    long long ans = 0;
    set<int> nxt;
    for (int i = 0; i < s.size(); i++)
    {
        nxt.insert(i);
    }
    for (int i = 0; i < s.size(); i++)
    {
        auto it = nxt.lower_bound(i);
        while (it != nxt.begin())
        {
            --it;
            if (s[*it] == 'z' - (s[i] - 'a'))
            {
                ans += i - *it;
                nxt.erase(it);
                nxt.erase(i);
                break;
            }
        }
    }
    cout << ans << '\n';
}