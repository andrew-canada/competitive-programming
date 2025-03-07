#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define endl "\n"

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

int n, k;
int ncr(int n, int r)
{
    int rr = 1;
    for (int i = n; i > n - r; i--)
        rr *= i;
    rep(i, 1, r + 1) rr /= i;
    return rr;
}
void solve()
{
    cin >> n >> k;
    map<int, int> mp = {
        {2, 1},
        {3, 2},
        {4, 9},
    };
    int ans = 1;
    for (int i = 2; i <= k; i++)
    {
        ans += ncr(n, i) * mp[i];
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}