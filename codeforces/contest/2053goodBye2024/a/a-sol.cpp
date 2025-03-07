#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
template <class T, class U>
inline bool chmax(T &a, U b) { return (a < b ? a = b, 1 : 0); }
template <class T, class U>
inline bool chmin(T &a, U b) { return (b < a ? a = b, 1 : 0); }
template <class T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    rep(i, si(v)) os << (i ? " " : "") << v[i];
    return os;
}
using ll = long long;
constexpr int inf = 1001001001;
constexpr long long infll = 4004004004004004004LL;

bool solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    rep(i, n - 1)
    {
        if (a[i] * 2 > a[i + 1] && a[i + 1] * 2 > a[i])
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests;
    cin >> tests;
    while (tests--)
    {
        cout << (solve() ? "Yes\n" : "No\n");
    }
}