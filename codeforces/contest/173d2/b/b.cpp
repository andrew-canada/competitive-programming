#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll n, d;
    cin >> t;
    while (t--)
    {
        cin >> n >> d;
        cout << "1 ";
        if (n >= 3 || d % 3 == 0)
        {
            cout << "3 ";
        }
        if (d == 5)
        {
            cout << "5 ";
        }
        if (n >= 3 || d == 7)
        {
            cout << "7 ";
        }
        if (n >= 6 || d == 9 || d % 3 == 0 && n >= 3)
        {
            cout << "9 ";
        }
        cout << '\n';
    }
}