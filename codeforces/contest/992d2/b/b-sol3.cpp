#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll ILL = 2167167167167167167;
const int INF = 2100000000;
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define all(p) p.begin(), p.end()
template <class T>
using _pq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
ll LB(vector<T> &v, T a) { return lower_bound(v.begin(), v.end(), a) - v.begin(); }
template <class T>
ll UB(vector<T> &v, T a) { return upper_bound(v.begin(), v.end(), a) - v.begin(); }
template <class T>
bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    else
        return 0;
}
template <class T>
bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    else
        return 0;
}
template <class T>
void So(vector<T> &v) { sort(v.begin(), v.end()); }
template <class T>
void Sore(vector<T> &v)
{
    sort(v.begin(), v.end(), [](T x, T y)
         { return x > y; });
}
bool yneos(bool a, bool upp = 0)
{
    if (a)
    {
        cout << (upp ? "YES\n" : "Yes\n");
    }
    else
    {
        cout << (upp ? "NO\n" : "No\n");
    }
    return a;
}
template <class T>
void vec_out(vector<T> &p, int ty = 0)
{
    if (ty == 2)
    {
        cout << '{';
        for (int i = 0; i < (int)p.size(); i++)
        {
            if (i)
            {
                cout << ",";
            }
            cout << '"' << p[i] << '"';
        }
        cout << "}\n";
    }
    else
    {
        if (ty == 1)
        {
            cout << p.size() << "\n";
        }
        for (int i = 0; i < (int)(p.size()); i++)
        {
            if (i)
                cout << " ";
            cout << p[i];
        }
        cout << "\n";
    }
}
template <class T>
T vec_min(vector<T> &a)
{
    assert(!a.empty());
    T ans = a[0];
    for (auto &x : a)
        chmin(ans, x);
    return ans;
}
template <class T>
T vec_max(vector<T> &a)
{
    assert(!a.empty());
    T ans = a[0];
    for (auto &x : a)
        chmax(ans, x);
    return ans;
}
template <class T>
T vec_sum(vector<T> &a)
{
    T ans = T(0);
    for (auto &x : a)
        ans += x;
    return ans;
}
int pop_count(long long a)
{
    int res = 0;
    while (a)
    {
        res += (a & 1), a >>= 1;
    }
    return res;
}

void solve();
// CITRUS CURIO CITY / FREDERIC
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    rep(i, 0, t) solve();
}

void solve()
{
    int N;
    cin >> N;
    int ans = 1;
    int M = 1;
    while (M < N)
    {
        ans++;
        M = M * 2 + 2;
    }
    cout << ans << "\n";
}