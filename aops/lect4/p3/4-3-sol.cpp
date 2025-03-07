#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct
{
    bool unlimited;
    ll w, t;
} platedata;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l, k;
    cin >> l >> k;

    vector<platedata> plates;
    while (k--)
    {
        ll n, w, t;
        cin >> n >> w >> t;
        if ((n + 1) * t > l)
        {
            // We have effectively infinity of these plates
            plates.push_back({true, w, t});
        }
        else
        {
            // Fuse plates into powers of 2 for efficiency
            int used = 0;
            for (int mult = 1; mult * 2 <= n; mult *= 2)
            {
                used += mult;
                plates.push_back({false, w * mult, t * mult});
            }
            int finalMult = n - used;
            plates.push_back({false, w * finalMult, t * finalMult});
        }
    }

    vector<ll> dpOld(l + 1, 0);
    for (auto [unlimited, w, t] : plates)
    {
        vector<ll> dpNew = {0};
        for (int j = 1; j <= l; j++)
        {
            ll bestimate = dpOld[j];
            if (t <= j)
            {
                vector<ll> &smallerCase = unlimited ? dpNew : dpOld;
                bestimate = max(bestimate, smallerCase[j - t] + w);
            }
            dpNew.push_back(bestimate);
        }
        dpOld = dpNew;
    }

    cout << dpOld[l] << endl;
    return 0;
}