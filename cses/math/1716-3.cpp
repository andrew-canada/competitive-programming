#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6, M = 1e9 + 7;

ll inv[2 * mxN + 1], fact[2 * mxN + 1], invFact[2 * mxN + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    inv[1] = 1;
    for (int i = 2; i <= 2 * mxN; i++)
    {
        inv[i] = M - (M / i) * inv[M % i] % M;
    }
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= 2 * mxN; i++)
    {
        // remember to mod
        fact[i] = i * fact[i - 1] % M;
        invFact[i] = inv[i] * invFact[i - 1] % M;
    }
    cout << fact[n + m - 1] * invFact[n - 1] % M * invFact[m] % M;
}