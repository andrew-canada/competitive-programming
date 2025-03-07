#include <bits/stdc++.h>

using namespace std;

constexpr int64_t MOD = 998244353;

constexpr int MAX = 3000000;
vector<int> phi_cache(MAX + 1);
vector<int64_t> fact(MAX + 1), inv_fact(MAX + 1);

int64_t good_exp(int64_t base, int64_t exp)
{
    int64_t result = 1;
    int64_t cur = base;
    while (0 < exp)
    {
        if (exp & 1)
            result = (1LL * result * cur) % MOD;
        cur = (cur * cur) % MOD;
        exp >>= 1;
    }
    return result;
}

int64_t inv(int64_t x) { return good_exp(x, MOD - 2); }

int64_t nCr(const vector<int> &d, int64_t const M_over_n)
{
    int64_t out = fact[M_over_n];
    for (int x : d)
        out = (1LL * out * inv_fact[x]) % MOD;
    return out;
}

vector<int> get_divisors(int const x)
{
    vector<int> out;
    for (int i = 1; i * i <= x; i++)
        if (x % i == 0)
        {
            out.push_back(i);
            if (i * i != x)
                out.push_back(x / i);
        }
    return out;
}

void test()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    vector<int> d(k);
    int64_t sum_d = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> d[i];
        sum_d += d[i];
    }
    int64_t const A = a, B = b, C = c;
    int64_t const M = A * B * C;

    int g = d[0];
    for (int i = 1; i < k; i++)
        g = gcd(g, d[i]);

    vector<int> Da = get_divisors(a);
    vector<int> Db = get_divisors(b);
    vector<int> Dc = get_divisors(c);

    ranges::sort(Da);
    ranges::sort(Db);
    ranges::sort(Dc);

    unordered_map<int, int64_t> f_map;
    f_map.reserve(Da.size() * Db.size() * Dc.size() * 2);
    f_map.max_load_factor(0.7);

    for (int const da : Da)
        for (int const db : Db)
        {
            int const l_ab_val = (da / gcd(da, db)) * db;
            for (int const dc : Dc)
                f_map[(l_ab_val / gcd(l_ab_val, dc)) * dc] += phi_cache[da] * phi_cache[db] * phi_cache[dc];
        }

    int64_t out = 0;
    for (pair<const int, int64_t> const &it : f_map)
    {
        int n = it.first;
        if (M % n != 0)
            continue;
        if (g % n != 0)
            continue;
        bool divisible = true;
        for (int x : d)
            if (x % n != 0)
            {
                divisible = false;
                break;
            }
        if (!divisible)
            continue;
        int64_t M_over_n = M / n;
        vector<int> d_div(k);
        for (int i = 0; i < k; i++)
            d_div[i] = d[i] / n;
        int64_t ways = nCr(d_div, M_over_n);
        int64_t val = ((it.second % MOD) * ways) % MOD;
        out += val;
        if (out >= MOD)
            out -= MOD;
    }

    cout << ((out * inv(M)) % MOD) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    iota(phi_cache.begin(), phi_cache.end(), 0);
    for (int i = 2; i <= MAX; i++)
        if (phi_cache[i] == i)
            for (int j = i; j <= MAX; j += i)
                phi_cache[j] -= phi_cache[j] / i;

    fact[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    inv_fact[MAX] = inv(fact[MAX]);
    for (int i = MAX - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;

    int tt;
    cin >> tt;
    while (tt--)
        test();

    return 0;
}
