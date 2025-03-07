#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, l, r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        int k = 31 - __builtin_clz(l ^ r);
        int a = l | ((1 << k) - 1), b = a + 1, c = (a == l ? r : l);
        cout << a << " " << b << " " << c << '\n';
    }
}