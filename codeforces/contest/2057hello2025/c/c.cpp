#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

ll pow2[31];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pow2[1] = 2;
    for (int i = 2; i <= 30; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
    }
    int t;
    ll l, r;
    vector<array<int, 3>> a({{1, 2, 0}, {8, 7, 1}, {2, 1, 3}, {7, 16, 11}, {134, 132, 137}, {98, 85, 76}, {123, 121, 118}, {965321865, 375544086, 12551794}});
    vector<array<int, 3>> b({{2, 1, 0}, {8, 7, 6}, {2, 1, 0}, {16, 15, 14}, {128, 127, 126}, {64, 63, 62}, {64, 63, 62}, {536870912, 536870911, 536870910}});
    for (int i = 0; i < 8; i++)
    {
        cout << i << '\n';
        cout << (a[i][0] ^ a[i][1]) + (a[i][0] ^ a[i][2]) + (a[i][1] ^ a[i][2]) << '\n';
        cout << (b[i][0] ^ b[i][1]) + (b[i][0] ^ b[i][2]) + (b[i][1] ^ b[i][2]) << '\n';
    }
    // cin >> t;
    // while (t--)
    // {
    //     cin >> l >> r;
    //     ll high;
    //     for (int i = 1; i <= 30; i++)
    //     {
    //         if (r >= pow2[i])
    //         {
    //             high = pow2[i];
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     cout << high << ' ' << high - 1 << ' ' << high - 2 << '\n';
    // }
}