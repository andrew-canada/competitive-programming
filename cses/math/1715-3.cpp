#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6, M = 1e9 + 7;

int freq[200];
ll fact[mxN + 1], inv[mxN + 1], invFact[mxN + 1];

int main()
{
    string s;
    cin >> s;
    for (char c : s)
    {
        freq[c]++;
    }
    inv[1] = 1;
    for (int i = 2; i <= mxN; i++)
    {
        inv[i] = M - (M / i) * inv[M % i] % M;
    }
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= mxN; i++)
    {
        fact[i] = i * fact[i - 1] % M;
        invFact[i] = inv[i] * invFact[i - 1] % M;
    }
    ll ans = fact[s.size()];
    for (int i = 'a'; i <= 'z'; i++)
    {
        ans = (ans * invFact[freq[i]]) % M;
    }
    cout << ans;
}