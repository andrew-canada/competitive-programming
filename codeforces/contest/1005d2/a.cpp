#include <bits/stdc++.h>
using namespace std;

int solve(const string &s)
{
    int n = s.size();
    int numOne = count(s.begin(), s.end(), '1');
    if (numOne == 0)
    {
        return 0;
    }
    if (numOne == n)
    {
        return 1;
    }
    int seg = 0;
    int i = 0;
    while (i < n)
    {
        if (s[i] == '1')
        {
            seg++;
            while (i < n && s[i] == '1')
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    // if (seg == 1 && s[n - 1] == '0')
    // {
    //     return 2;
    // }
    return 2 * seg - (s[n - 1] == '0' ? 0 : 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        cout << solve(s) << '\n';
    }
}