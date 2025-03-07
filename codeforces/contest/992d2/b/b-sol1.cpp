#include <bits/stdc++.h>
#define N (200000 + 10) /*------------------ #define ------------------*/
#define M (400000 + 10)
#define MOD (1000000000 + 7)
// #define MOD (998244353)
#define INF (0x3f3f3f3f)
#define LNF (3e18)
#define mod(a, b) (((a) % (b) + (b)) % (b))
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define fi first
#define se second
#define vvi vector<vector<int>>
#define vi vector<int>
#define vvl vector<vector<LL>>
#define vl vector<LL>
#define _vvi(n, m, k) vector<vector<int>>(n, vector<int>(m, k))
#define _vi(n, k) vector<int>(n, k)
#define _vvl(n, m, k) vector<vector<LL>>(n, vector<LL>(m, k))
#define _vl(n, k) vector<LL>(n, k)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;

auto solve()
{

    LL n;
    cin >> n;

    LL ans = 1, now = 1, l = 2;

    while (now < n)
    {
        ans++;
        now += 1 + l;
        l = l * 2 + 1;
    }

    cout << ans << '\n';
}

signed main()
{
    IOS int T = 1;
    cin >> T;
    while (T--)
        solve();
    // while(T -- ) cout << (solve() ? "YES" : "NO") << '\n';

    return 0;
}