#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];
map<ll, int> mp;

int main()
{
    ll n, x;
    cin >> n >> x;
    ll cs = 0, ans = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cs += arr[i];
        ans += mp[cs - x];
        mp[cs] = 1;
    }
    cout << ans;
}