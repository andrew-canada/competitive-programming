#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxA = 1e6, M = 1e9 + 7;

ll fact[mxA], inv[mxA], invFact[mxA];

int main()
{
    int n;
    cin >> n;
    inv[1] = 1;
    for (int i = 2; i <= mxA; i++)
    {
        inv[i] = M - (M / i) * inv[M % i] % M;
    }
    // 0, not 1
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= mxA; i++)
    {
        fact[i] = i * fact[i - 1] % M;
        invFact[i] = inv[i] * invFact[i - 1] % M;
    }
    for (int i = 0, a, b; i < n; i++)
    {
        cin >> a >> b;
        cout << fact[a] * invFact[b] % M * invFact[a - b] % M << '\n';
    }
}