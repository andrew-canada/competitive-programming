#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mmod 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout.flush();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        cout << 1 << " ";
        if (d % 3 == 0 || n >= 3)
        {
            cout << 3 << " ";
        }
        if (d == 5)
        {
            cout << 5 << " ";
        }
        if (d == 7 || n >= 3)
        {
            cout << 7 << " ";
        }
        if (d == 9 || (d % 3 == 0 && n >= 3) || (n >= 6))
        {
            cout << 9 << " ";
        }
        cout << endl;
    }
    return 0;
}