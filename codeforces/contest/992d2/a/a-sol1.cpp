#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << "\n"
#define debugs(x) cerr << #x << " " << x << " "
#define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 400005;

signed main()
{
#ifdef HOME
    ifstream cin(".in");
    ofstream cout(".out");
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, i, a = 0, b = 0, c = 0;
    string s;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> n >> k;
        map<int, int> mp;
        for (i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (mp.find(x % k) == mp.end())
            {
                mp[x % k] = i;
            }
            else
            {
                mp[x % k] = -i;
            }
        }
        int ok = 1;
        for (auto x : mp)
        {
            if (x.second > 0)
            {
                cout << "YES\n";
                cout << x.second << "\n";
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << "NO\n";
        }
    }
    return 0;
}
