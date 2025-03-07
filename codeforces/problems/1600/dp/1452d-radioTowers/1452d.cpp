#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 998244353, mxN = 2e5;

int fib[mxN + 1];

ll mult(ll x, ll y)
{
    int ans = 1;
    while (y > 0)
    {
        if (y % 2)
        {
            ans = (ans * x) % M;
        }
        x = (x * x) % M;
        y >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % M;
    }
    cout << fib[n] * mult(mult(2, n), M - 2) % M << '\n';
}