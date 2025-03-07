#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll modexp(ll w, ll curr, ll m)
{
    ll modded_m_power = m;
    while (w > 0)
    {
        if (w % 2 == 1)
        {
            curr *= modded_m_power;
            curr %= MOD;
        }
        w /= 2;
        modded_m_power *= modded_m_power; // square
        modded_m_power %= MOD;
    }
    return curr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll c, w, a, m;
    cin >> c >> w >> a >> m;
    ll answer = c;
    if (m == 1)
    { // just add
        answer += w * a;
        answer %= MOD;
    }
    else if (c + a <= c * m)
    { // just multiply
        answer = modexp(w, answer, m);
    }
    else
    { // add once, then multiply
        answer += a;
        answer %= MOD;
        answer = modexp(w - 1, answer, m);
    }
    cout << answer << '\n';
}