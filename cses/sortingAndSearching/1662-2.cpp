#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];
map<ll, int> mp;

int main()
{
    int n;
    cin >> n;
    ll cs = 0, ans = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cs = (cs + arr[i] % n + n) % n;
        ans += mp[cs];
        mp[cs]++;
    }
    cout << ans;
}