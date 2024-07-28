#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];
map<ll, int> mp;

int main()
{
    int n, x;
    cin >> n >> x;
    mp[0] = 1;
    ll cs = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cs += arr[i];
        ans += mp[cs - x];
        mp[cs]++;
    }
    cout << ans;
}