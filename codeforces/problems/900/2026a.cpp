#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, x, y, k;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> k;
        int sl = min(x, y);
        cout << "0 0 " << sl << " " << sl << '\n';
        cout << "0 " << sl << " " << sl << " 0" << '\n';
    }
}