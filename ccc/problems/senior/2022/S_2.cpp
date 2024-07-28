#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

map<string, int> group;
string same1[mxN + 1], same2[mxN + 1], diff1[mxN + 1], diff2[mxN + 1];

int main()
{
    int s, d, g;
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        cin >> same1[i] >> same2[i];
    }
    cin >> d;
    for (int i = 0; i < d; i++)
    {
        cin >> diff1[i] >> diff2[i];
    }
    cin >> g;
    string a, b, c;
    for (int i = 0; i < g; i++)
    {
        cin >> a >> b >> c;
        group[a] = group[b] = group[c] = i;
    }
    int ans = 0;
    for (int i = 0; i < s; i++)
    {
        if (group[same1[i]] != group[same2[i]])
        {
            ans++;
        }
    }
    for (int i = 0; i < d; i++)
    {
        if (group[diff1[i]] == group[diff2[i]])
        {
            ans++;
        }
    }
    cout << ans;
}