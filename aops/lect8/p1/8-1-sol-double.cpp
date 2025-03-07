#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int rp, cp, rg, cg;
    cin >> rp >> cp >> rg >> cg;
    // All that matters is the size of the pattern, so we don't bother to read it
    double total_prob = 0.0;
    for (int mult = 1; ((mult * rp <= rg) && (mult * cp <= cg)); ++mult)
    {
        int new_rp = mult * rp;
        int new_cp = mult * cp;
        double pattern_prob = 1.0;
        for (int k = 0; k < (new_rp * new_cp); ++k)
        {
            pattern_prob /= 2;
        }
        double available_blocks = (double)((rg - new_rp + 1) * (cg - new_cp + 1));
        total_prob += available_blocks * pattern_prob;
    }
    cout << fixed << setprecision(9) << total_prob << '\n';
}