#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define ff first
#define ss second
#define sz(a) (int)(a.size())
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define INF 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

const int MOD = 998244353;
const int MAX_N = 3000000;

vector<int> sieve_phi(int max_n)
{
    vector<int> phi(max_n + 1, 0);
    for (int i = 0; i <= max_n; i++)
        phi[i] = i;
    for (int p = 2; p <= max_n; p++)
    {
        if (phi[p] == p)
        {
            for (int multiple = p; multiple <= max_n; multiple += p)
            {
                phi[multiple] -= phi[multiple] / p;
            }
        }
    }
    return phi;
}

vector<long long> precompute_fact(int max_n)
{
    vector<long long> fact(max_n + 1, 1);
    for (int i = 1; i <= max_n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    return fact;
}

vector<long long> precompute_inv_fact(int max_n, const vector<long long> &fact)
{
    vector<long long> inv_fact(max_n + 1, 1);
    ll inv = 1;
    auto power = [&](ll a, ll b) -> ll
    {
        ll res = 1;
        a %= MOD;
        while (b > 0)
        {
            if (b & 1)
            {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    };
    inv = power(fact[max_n], MOD - 2);
    inv_fact[max_n] = inv;
    for (int i = max_n - 1; i >= 0; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
    return inv_fact;
}

vector<int> list_divisors(int n)
{
    vector<int> divisors = {1};
    vector<pair<int, int>> factors;
    int x = n;
    for (int p = 2; p * p <= x; p++)
    {
        if (x % p == 0)
        {
            int cnt = 0;
            while (x % p == 0)
            {
                cnt++;
                x /= p;
            }
            factors.emplace_back(make_pair(p, cnt));
        }
    }
    if (x > 1)
    {
        factors.emplace_back(make_pair(x, 1));
    }
    for (auto &[p, cnt] : factors)
    {
        int sz = divisors.size();
        vector<int> tmp;
        int power = 1;
        for (int i = 1; i <= cnt; i++)
        {
            power *= p;
            for (int j = 0; j < sz; j++)
            {
                tmp.pb(divisors[j] * power);
            }
        }
        for (auto d : tmp)
        {
            divisors.pb(d);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> phi = sieve_phi(MAX_N);
    vector<long long> fact = precompute_fact(MAX_N);
    vector<long long> inv_fact = precompute_inv_fact(MAX_N, fact);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        vector<int> di(k);
        for (int &x : di)
            cin >> x;
        vector<int> divisors_x = list_divisors(a);
        vector<int> divisors_y = list_divisors(b);
        vector<int> divisors_z = list_divisors(c);
        int lcm_max = a * b * c;
        unordered_map<int, long long> counts_l_map;
        for (auto l_x : divisors_x)
        {
            long long Nx = (l_x == 1) ? 1 : (long long)phi[l_x];
            for (auto l_y : divisors_y)
            {
                long long Ny = (l_y == 1) ? 1 : (long long)phi[l_y];
                ll lcm_xy = l_x;
                ll g_xy = __gcd(l_x, l_y);
                lcm_xy = ((ll)l_x / g_xy) * l_y;
                for (auto l_z : divisors_z)
                {
                    long long Nz = (l_z == 1) ? 1 : (long long)phi[l_z];
                    ll l = lcm_xy;
                    ll g_lz = __gcd(lcm_xy, (ll)l_z);
                    l = (lcm_xy / g_lz) * l_z;
                    counts_l_map[l] += Nx * Ny * Nz;
                }
            }
        }
        ll sum_Fix = 0;
        ll total_cubes = (ll)a * b * c;
        for (auto &[l, cnt_l] : counts_l_map)
        {
            bool divisible = true;
            for (int i = 0; i < k; i++)
            {
                if (di[i] % l != 0)
                {
                    divisible = false;
                    break;
                }
            }
            if (!divisible)
            {
                continue;
            }
            bool valid = true;
            ll numberofc = total_cubes / l;
            ll sum_c_i = 0;
            ll num = fact[numberofc];
            ll denom = 1;
            for (int i = 0; i < k; i++)
            {
                ll ci = di[i] / l;
                sum_c_i += ci;
                denom = denom * inv_fact[ci] % MOD;
            }
            if (sum_c_i != numberofc)
            {
                continue;
            }
            ll Fix_l = fact[numberofc] * denom % MOD;
            sum_Fix = (sum_Fix + cnt_l * Fix_l) % MOD;
        }
        ll G = (ll)a * b % MOD;
        G = G * c % MOD;
        auto power = [&](ll a, ll b) -> ll
        {
            ll res = 1;
            a %= MOD;
            while (b > 0)
            {
                if (b & 1)
                {
                    res = res * a % MOD;
                }
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        };
        ll inv_G = power(G, MOD - 2);
        ll answer = sum_Fix * inv_G % MOD;
        cout << answer << "\n";
    }
}