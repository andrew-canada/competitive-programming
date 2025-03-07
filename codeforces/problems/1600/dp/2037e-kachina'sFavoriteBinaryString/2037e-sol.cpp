#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define vint vector<int>
#define pb push_back
#define r0 return 0
#define f0(i, n) for (int i = 0; i < (int)n; ++i)
#define f1(i, n) for (int i = 1; i <= (int)n; ++i)
#define nl '\n'
#define take(a, n) \
    vint a(n);     \
    f0(i, n) cin >> a[i];
#define give(a, n)                        \
    {                                     \
        f0(i, n) { cout << a[i] << ' '; } \
        cout << nl;                       \
    }
#define MOD 1000000007
#define MOD1 998244353
#define pii pair<int, int>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define set_bits __builtin_popcountll
#define int long long
#define float double
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fr first
#define sc second
#define vvint vector<vint>
#define INF 1e18

#define debug(x)           \
    {                      \
        cout << #x << " "; \
        _print(x);         \
        cout << endl;      \
    }

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
// use less_equal for multiple entries
typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;

void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(lld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cout << "{";
    _print(p.fr);
    cout << ",";
    _print(p.sc);
    cout << "}";
}
template <class T>
void _print(vector<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(set<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cout << "[ ";
    for (auto i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
void _print(pbds v)
{
    cout << "[ ";
    for (auto i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/

// Think of more general solutions
// Be careful with variables
// Remember 0 is 0LL, 1 is 1LL
// Write down all the observations

void solve()
{
    int n;
    cin >> n;
    vint ans(n + 1);
    cout << "? ";
    cout << 1 << ' ' << n << endl;
    int k;
    cin >> k;
    if (k == 0)
    {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }
    int prev = 1;
    bool zero = false;
    int val = -1;
    for (int i = 2; i <= n; ++i)
    {
        cout << "? ";
        cout << prev << ' ' << i << endl;
        int r;
        cin >> r;
        if (!zero && r > 0)
        {
            zero = true;
            prev = i - 1;
            ans[i] = 1;
            val = 1;
            for (int j = i - 1; j >= i - r; --j)
            {
                ans[j] = 0;
            }
            for (int j = i - r - 1; j >= 1; --j)
            {
                ans[j] = 1;
            }
            continue;
        }
        if (zero)
        {
            if (val == r)
                ans[i] = 0;
            else
            {
                val = r;
                ans[i] = 1;
            }
        }
    }
    cout << "! ";
    f1(i, n)
    {
        cout << ans[i];
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed << setprecision(10);
    test
    solve();

    return 0;
}