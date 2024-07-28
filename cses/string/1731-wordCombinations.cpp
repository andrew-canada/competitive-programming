#include <bits/stdc++.h>

using namespace std;

const int mxN = 5e3, M = 1e9 + 7;

int dp[mxN + 1];
string d[mxN + 1];

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    dp[0] = 1;
}