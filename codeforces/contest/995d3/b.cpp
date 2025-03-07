#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b >> c;
        int d = ceil(1.0 * n / (a + b + c));
        int tot = (a + b + c) * d;
        if (tot - c - b >= n)
        {
            cout << 3 * d - 2 << '\n';
            continue;
        }
        if (tot - c >= n)
        {
            cout << 3 * d - 1 << '\n';
            continue;
        }
        cout << 3 * d << '\n';
    }
}