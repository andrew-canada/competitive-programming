#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (ll i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    cout << ans;
}