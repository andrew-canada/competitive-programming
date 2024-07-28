#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        ll ng = i * i, nw = ng * (ng - 1) / 2;
        if (i > 2)
        {
            nw -= 4 * (i - 1) * (i - 2);
        }
        cout << nw << '\n';
    }
}