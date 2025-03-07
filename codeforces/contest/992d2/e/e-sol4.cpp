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

std::vector<std::vector<int>> tree_in(int N)
{
    std::vector<std::vector<int>> G(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    return G;
}
std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> tree_order_pare_depth(std::vector<std::vector<int>> &G, int root)
{
    int n = G.size();
    std::vector<int> order = {root}, pare(n, -1), depth(n);
    pare[root] = -2;
    for (int i = 0; i < n; i++)
    {
        int a = order[i];
        for (auto x : G[a])
        {
            if (pare[x] == -1)
            {
                pare[x] = a;
                depth[x] = depth[a] + 1;
                order.push_back(x);
            }
        }
    }
    return {order, pare, depth};
}
std::vector<int> tree_diameter_path(std::vector<std::vector<int>> &G)
{
    int n = G.size();
    auto r = (std::get<0>(tree_order_pare_depth(G, 0))).at(n - 1);
    std::vector<int> order, pare, depth, ans;
    tie(order, pare, depth) = tree_order_pare_depth(G, r);
    int ind = order[n - 1];
    while (ind != -2)
    {
        ans.push_back(ind);
        ind = pare[ind];
    }
    return ans;
}

// a以下の素数を列挙、計算量:Nlog(log(N))
vector<long long> Eratosthenes(long long a)
{
    if (a < 2)
        return {};
    vector<long long> p(a + 1), ans;
    p[0] = 1, p[1] = 1;
    long long k = 2;
    while (k * k <= a)
    {
        if (p[k] == 0)
        {
            ans.push_back(k);
            for (long long i = 2; i * k <= a; i++)
            {
                p[i * k] = 1;
            }
        }
        k++;
    }
    while (k <= a)
    {
        if (p[k] == 0)
            ans.push_back(k);
        k++;
    }
    return p;
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
    int N, Q;
    cin >> N >> Q;
    auto G = tree_in(N);
    auto [order, pare, depth] = tree_order_pare_depth(G, 0);
    vector<vector<int>> H(N);
    rep(rp, 1, N)
    {
        int i = order[rp];
        if (pare[i] == 0)
            continue;
        H[i] = H[pare[pare[i]]];
        H[i].push_back(G[pare[i]].size());
        So(H[i]);
    }
    while (Q--)
    {
        int a, p;
        cin >> a >> p;
        a--;
        int ans = depth[a];
        rep(i, 0, (int)H[a].size() - p) ans += H[a][i] * 2 - 2;
        cout << ans << "\n";
    }
}
