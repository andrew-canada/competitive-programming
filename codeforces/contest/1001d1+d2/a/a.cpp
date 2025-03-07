#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string s;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        cin >> s;
        for (char c : s)
        {
            if (c == '1')
            {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}