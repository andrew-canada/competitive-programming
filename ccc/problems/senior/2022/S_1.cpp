#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while (n >= 0)
    {
        if (n % 4 == 0)
        {
            ans++;
        }
        n -= 5;
    }
    cout << ans;
}