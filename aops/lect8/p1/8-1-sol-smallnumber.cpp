#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int rp, cp, rg, cg;
    cin >> rp >> cp >> rg >> cg;
    // All that matters is the size of the pattern, so we don't bother to read it
    vector<pair<int, double>> probs;
    for (int mult = 1; ((mult * rp <= rg) && (mult * cp <= cg)); ++mult)
    {
        int new_rp = mult * rp;
        int new_cp = mult * cp;
        int pattern_exponent = -(new_rp * new_cp);
        double available_blocks = (double)((rg - new_rp + 1) * (cg - new_cp + 1));
        // This could be made faster, of course
        while (available_blocks >= 2)
        {
            available_blocks /= 2;
            pattern_exponent++;
        }
        probs.push_back(make_pair(pattern_exponent, available_blocks));
    }
    sort(probs.begin(), probs.end());
    int curr_exp = probs[0].first;
    double curr_mag = probs[0].second;
    int next_exp;
    double next_mag;
    for (int i = 1; i < probs.size(); ++i)
    {
        next_exp = probs[i].first;
        next_mag = probs[i].second;
        while (curr_exp < next_exp)
        {
            curr_exp++;
            curr_mag /= 2;
        }
        curr_mag += next_mag;
    }
    double answer;
    double mult = 1.0;
    if (curr_exp <= 0)
    {
        while (curr_exp < 0)
        {
            curr_exp++;
            mult /= 2;
        }
    }
    else
    {
        while (curr_exp > 0)
        {
            curr_exp--;
            mult *= 2;
        }
    }
    answer = curr_mag * mult;
    cout << fixed << setprecision(9) << answer << '\n';
}