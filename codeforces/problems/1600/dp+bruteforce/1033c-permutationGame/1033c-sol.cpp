#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) int(x.size())
#define rotate(l, r) rotate(p.begin() + l, p.begin() + r, p.begin() + r + 1)
#define endl "\n"
const double eps = 10e-7;
const int MOD = 1000000007;
const int mod = 998244353;
const int inf = 1e9;
const ll INF = 2e18;
const int N = 100005;

int cbit(int x)
{
    return __builtin_popcount(x);
}
long long binpow(long long a, long long b, long long MOD)
{
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2, MOD);
    if (b % 2)
        return res % MOD * res % MOD * a % MOD;
    else
        return res % MOD * res % MOD;
}

// special cases && implementation
// https://codeforces.com/contest/448 T.T.C
// https://codeforces.com/contest/977/problem/F
// https://discuss.codechef.com/t/segment-tree-problems-of-codeforces-edu-with-code-and-some-explanation/82461/5
// https://docs.google.com/document/d/1E8j0FCoNbdptnaPxwmeaRqp6UkTGPg-6NUjLGJDNGMI/edit

void solve()
{
    int n;
    cin >> n;
    int arr[n + 1], pos[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i], pos[arr[i]] = i;
    string win(n + 1, '?');
    for (int x = n; x >= 1; x--)
    {
        int i = pos[x];
        int j = i;
        win[i] = 'B';
        while (true)
        {
            j -= x;
            if (j <= 0)
                break;
            if (win[j] == 'B')
            {
                win[i] = 'A';
                break;
            }
        }
        j = i;
        while (true)
        {
            j += x;
            if (j > n)
                break;
            if (win[j] == 'B')
            {
                win[i] = 'A';
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << win[i];
}

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("moocast");
    int tc = 1;
    // cin >> tc ;
    while (tc--)
    {
        solve();
    }
    return 0;
}