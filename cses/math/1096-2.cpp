#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<vector<ll>> mat;

const int M = 1e9 + 7, mxX = 1e6, mxN = 2e5;

mat mult(const mat &a, const mat &b)
{
    mat res(a.size(), vector<ll>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            for (int k = 0; k < b[0].size(); k++)
            {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % M) % M;
            }
        }
    }
    return res;
}

int main()
{
    ll n;
    cin >> n;
    mat a = {{0, 0, 0, 0, 0, 1}};
    mat b = {
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1}};
    while (n)
    {
        if (n & 1)
        {
            a = mult(a, b);
        }
        b = mult(b, b);
        n >>= 1;
    }
    cout << a[0][5];
}