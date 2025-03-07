// LUOGU_RID: 161051822
#if defined(LOCAL) or not defined(LUOGU)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#endif
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
namespace Fread
{
    const int SIZE = 1 << 16;
    char buf[SIZE], *S, *T;
    inline char getchar()
    {
        if (S == T)
        {
            T = (S = buf) + fread(buf, 1, SIZE, stdin);
            if (S == T)
                return '\n';
        }
        return *S++;
    }
}
namespace Fwrite
{
    const int SIZE = 1 << 16;
    char buf[SIZE], *S = buf, *T = buf + SIZE;
    inline void flush()
    {
        fwrite(buf, 1, S - buf, stdout);
        S = buf;
    }
    inline void putchar(char c)
    {
        *S++ = c;
        if (S == T)
            flush();
    }
    struct NTR
    {
        ~NTR() { flush(); }
    } ztr;
}
#define getchar Fread::getchar
#define putchar Fwrite::putchar
#define Setprecision 10
#define between '\n'
#define __int128 long long
template <typename T>
struct is_char
{
    static constexpr bool value = (std::is_same<T, char>::value || std::is_same<T, signed char>::value || std::is_same<T, unsigned char>::value);
};
template <typename T>
struct is_integral_ex
{
    static constexpr bool value = (std::is_integral<T>::value || std::is_same<T, __int128>::value) && !is_char<T>::value;
};
template <typename T>
struct is_floating_point_ex
{
    static constexpr bool value = std::is_floating_point<T>::value || std::is_same<T, __float128>::value;
};
namespace Fastio
{
    struct Reader
    {
        template <typename T>
        typename std::enable_if_t<std::is_class<T>::value, Reader &> operator>>(T &x)
        {
            for (auto &y : x)
                *this >> y;
            return *this;
        }
        template <typename T>
        typename std::enable_if_t<is_integral_ex<T>::value, Reader &> operator>>(T &x)
        {
            char c = getchar();
            short f = 1;
            while (c < '0' || c > '9')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            x = 0;
            while (c >= '0' && c <= '9')
            {
                x = (x << 1) + (x << 3) + (c ^ 48);
                c = getchar();
            }
            x *= f;
            return *this;
        }
        template <typename T>
        typename std::enable_if_t<is_floating_point_ex<T>::value, Reader &> operator>>(T &x)
        {
            char c = getchar();
            short f = 1, s = 0;
            x = 0;
            T t = 0;
            while ((c < '0' || c > '9') && c != '.')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            while (c >= '0' && c <= '9' && c != '.')
                x = x * 10 + (c ^ 48), c = getchar();
            if (c == '.')
                c = getchar();
            else
                return x *= f, *this;
            while (c >= '0' && c <= '9')
                t = t * 10 + (c ^ 48), s++, c = getchar();
            while (s--)
                t /= 10.0;
            x = (x + t) * f;
            return *this;
        }
        template <typename T>
        typename std::enable_if_t<is_char<T>::value, Reader &> operator>>(T &c)
        {
            c = getchar();
            while (c == '\n' || c == ' ' || c == '\r')
                c = getchar();
            return *this;
        }
        Reader &operator>>(char *str)
        {
            int len = 0;
            char c = getchar();
            while (c == '\n' || c == ' ' || c == '\r')
                c = getchar();
            while (c != '\n' && c != ' ' && c != '\r')
                str[len++] = c, c = getchar();
            str[len] = '\0';
            return *this;
        }
        Reader &operator>>(std::string &str)
        {
            str.clear();
            char c = getchar();
            while (c == '\n' || c == ' ' || c == '\r')
                c = getchar();
            while (c != '\n' && c != ' ' && c != '\r')
                str.push_back(c), c = getchar();
            return *this;
        }
        Reader() {}
    } cin;
    const char endl = '\n';
    struct Writer
    {
        typedef __int128 mxdouble;
        template <typename T>
        typename std::enable_if_t<std::is_class<T>::value, Writer &> operator<<(T x)
        {
            for (auto &y : x)
                *this << y << between;
            *this << '\n';
            return *this;
        }
        template <typename T>
        typename std::enable_if_t<is_integral_ex<T>::value, Writer &> operator<<(T x)
        {
            if (x == 0)
                return putchar('0'), *this;
            if (x < 0)
                putchar('-'), x = -x;
            static int sta[45];
            int top = 0;
            while (x)
                sta[++top] = x % 10, x /= 10;
            while (top)
                putchar(sta[top] + '0'), --top;
            return *this;
        }
        template <typename T>
        typename std::enable_if_t<is_floating_point_ex<T>::value, Writer &> operator<<(T x)
        {
            if (x < 0)
                putchar('-'), x = -x;
            x += pow(10, -Setprecision) / 2;
            mxdouble _ = x;
            x -= (T)_;
            static int sta[45];
            int top = 0;
            while (_)
                sta[++top] = _ % 10, _ /= 10;
            if (!top)
                putchar('0');
            while (top)
                putchar(sta[top] + '0'), --top;
            putchar('.');
            for (int i = 0; i < Setprecision; i++)
                x *= 10;
            _ = x;
            while (_)
                sta[++top] = _ % 10, _ /= 10;
            for (int i = 0; i < Setprecision - top; i++)
                putchar('0');
            while (top)
                putchar(sta[top] + '0'), --top;
            return *this;
        }
        template <typename T>
        typename std::enable_if_t<is_char<T>::value, Writer &> operator<<(T c)
        {
            putchar(c);
            return *this;
        }
        Writer &operator<<(char *str)
        {
            int cur = 0;
            while (str[cur])
                putchar(str[cur++]);
            return *this;
        }
        Writer &operator<<(const char *str)
        {
            int cur = 0;
            while (str[cur])
                putchar(str[cur++]);
            return *this;
        }
        Writer &operator<<(std::string str)
        {
            int st = 0, ed = str.size();
            while (st < ed)
                putchar(str[st++]);
            return *this;
        }
        Writer() {}
    } cout;
}
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl

void solve();
main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + m + 1), b(n + m + 1), op1(n + m + 1), op2(n + m + 1);
    cin >> a >> b;
    long long ans1 = 0, ans2 = 0;
    int c1 = 0, c2 = 0, cc = 0;
    for (int x = 0; x <= n + m; x++)
    {
        cc += a[x] > b[x];
        if ((a[x] > b[x] && c1 <= n) || m == x - c1)
            c1++, ans1 += a[x], op1[x] = 1;
        else
            ans1 += b[x];
        if ((a[x] < b[x] && c2 <= m) || n == x - c2)
            c2++, ans2 += b[x], op2[x] = 1;
        else
            ans2 += a[x];
    }
    if (cc <= n)
        op1 = move(op2), swap(ans1, ans2), swap(a, b);
    for (int x = 0; x <= n + m; x++)
        cout << (op1[x] ? ans1 - a[x] : ans2 - b[x]) << ' ';
    cout << endl;
}
