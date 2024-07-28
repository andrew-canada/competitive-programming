#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll ms = -1e18, msf = -1e18;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        msf = max(0ll + x, msf + x);
        ms = max(ms, msf);
    }
    cout << ms;
}