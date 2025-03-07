#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define ci const int
inline int max(ci &x, ci &y) { return x > y ? x : y; }
inline int min(ci &x, ci &y) { return x < y ? x : y; }
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
inline void chmax(ll &x, ll y)
{
    if (x < y)
        x = y;
}
inline void chmin(int &x, ci &y)
{
    if (x > y)
        x = y;
}
#define rei register int
#define mp make_pair
#define fi first
#define se second
#define rep(i, l, r) for (rei i = l, i##end = r; i <= i##end; ++i)
#define per(i, r, l) for (rei i = r, i##end = l; i >= i##end; --i)
char inputbuf[1 << 23], *p1 = inputbuf, *p2 = inputbuf;
#define getchar() (p1 == p2 && (p2 = (p1 = inputbuf) + fread(inputbuf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
inline int read()
{
    int res = 0;
    char ch = getchar();
    bool f = true;
    for (; ch < '0' || ch > '9'; ch = getchar())
        f &= ch != '-';
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        res = res * 10 + (ch ^ 48);
    return f ? res : -res;
}
const int N = 2e5 + 15;
ll a[N], l, r, n, k;
bool f;

signed main()
{
    for (int T = read(); T; --T)
    {
        n = read();
        k = read();
        rep(i, 1, n) a[i] = read();
        f = 1;
        l = r = a[1];
        rep(i, 2, n)
        {
            l = max(a[i], l - k + 1);
            r = min(r + k - 1, a[i] + k - 1);
            if (l > r)
            {
                f = 0;
                break;
            }
        }
        if (l != a[n])
            f = 0;
        if (f)
            puts("Yes");
        else
            puts("No");
    }
    return 0; //
}