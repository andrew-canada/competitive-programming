#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            ans++;
        }
        else
        {
            int q = n / 2;
            if (q % 2 == 0)
            {
                q++;
            }
            while (q > 0)
            {
                int prev = n - q;
                if (prev % q == 0)
                {
                    n = prev;
                    ans += n / q;
                    break;
                }
                q -= 2;
            }
        }
    }
    cout << ans;
}