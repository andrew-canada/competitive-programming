#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sumDig(ll x)
{
    ll sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, s;
    cin >> n >> s;

    ll firstBig = n + 1;

    ll low = 1, high = n, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid - sumDig(mid) >= s)
        {
            firstBig = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (firstBig > n)
    {
        cout << "0\n";
    }
    else
    {
        cout << n - firstBig + 1 << '\n';
    }
}