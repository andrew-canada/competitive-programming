#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;

const int mxN = 1e6, M = 1e9 + 7;

mat mult(const mat &a, const mat &b)
{
    mat ans(a.size(), vector<ll>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            for (int k = 0; k < b[0].size(); k++)
            {
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j] % M) % M;
            }
        }
    }
    return ans;
}

int main()
{
    mat a = {{0, 1}};
    mat b = {{0, 1}, {1, 1}};
    ll n;
    cin >> n;
    while (n)
    {
        if (n & 1)
        {
            a = mult(a, b);
        }
        n >>= 1;
        b = mult(b, b);
    }
    cout << a[0][0];
}