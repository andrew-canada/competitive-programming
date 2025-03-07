#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = 0;
        while (n)
        {
            n /= 4;
            ++ans;
        }
        --ans;
        cout << (int)pow(2, ans) << '\n';
    }
}