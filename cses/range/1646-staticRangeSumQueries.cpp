#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

ll psa[mxN];

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }
    int a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        cout << psa[b] - psa[a - 1] << '\n';
    }
}