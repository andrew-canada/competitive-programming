#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e6;

int bigFact[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            bigFact[j] = i;
        }
    }

    sort(bigFact + 1, bigFact + n + 1);

    int b;
    for (int i = 0; i < q; i++)
    {
        cin >> b;
        cout << bigFact[b];
        if (i < q - 1)
        {
            cout << " ";
        }
    }
}