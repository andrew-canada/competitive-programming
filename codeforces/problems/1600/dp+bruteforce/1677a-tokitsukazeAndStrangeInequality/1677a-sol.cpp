#include <bits/stdc++.h>
using namespace std;
/************* debug begin *************/
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool &b) { return (b ? "true" : "false"); }
template <class T>
string to_string(T x)
{
    ostringstream sout;
    sout << x;
    return sout.str();
}
template <class A, class B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <class A>
string to_string(const vector<A> v)
{
    int f = 1;
    string res = "{";
    for (const auto x : v)
    {
        if (!f)
            res += ", ";
        f = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out() { puts(""); }
template <class T, class... U>
void debug_out(const T &h, const U &...t)
{
    cout << " " << to_string(h);
    debug_out(t...);
}
#ifdef tokitsukaze
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
/*************  debug end  *************/
#define mem(a, b) memset((a), (b), sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define sqr(x) (x) * (x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
/************* define end  *************/
void println(VI x)
{
    for (int i = 0; i < sz(x); i++)
        printf("%d%c", x[i], " \n"[i == sz(x) - 1]);
}
void println(VL x)
{
    for (int i = 0; i < sz(x); i++)
        printf("%lld%c", x[i], " \n"[i == sz(x) - 1]);
}
void println(int *x, int l, int r)
{
    for (int i = l; i <= r; i++)
        printf("%d%c", x[i], " \n"[i == r]);
}
void println(ll *x, int l, int r)
{
    for (int i = l; i <= r; i++)
        printf("%lld%c", x[i], " \n"[i == r]);
}
/*************** IO end  ***************/
void go();
int main()
{
#ifdef tokitsukaze
    freopen("TEST.txt", "r", stdin);
#endif
    go();
    return 0;
}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int MAX = 1e5 + 10;
const ll mod = 998244353;
/*********************************  head  *********************************/
int a[MAX];
ll f[MAX], bitf[MAX];
void go()
{
    int n, i, j, k, l, T;
    ll ans;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        mem(f, 0);
        for (j = 1; j <= n; j++)
        {
            for (l = j + 1; l <= n; l++)
            {
                if (a[j] > a[l])
                    f[j]++;
            }
        }
        ans = 0;
        for (k = 1; k <= n; k++)
        {
            for (j = 1; j < k; j++)
            {
                if (a[j] > a[k])
                    f[j]--;
            }
            bitf[0] = 0;
            for (i = 1; i <= k; i++)
                bitf[i] = bitf[i - 1] + f[i];
            for (i = 1; i < k; i++)
            {
                if (a[i] < a[k])
                    ans += bitf[k - 1] - bitf[i];
            }
        }
        printf("%lld\n", ans);
    }
}
