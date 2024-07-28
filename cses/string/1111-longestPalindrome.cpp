#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 5e3;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0, idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i + j < n && i - j >= 0; j++)
        {
            if (s[i + j] == s[i - j])
            {
                if (2 * j + 1 > ans)
                {
                    ans = 2 * j + 1;
                    idx = i - j;
                }
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i + j + 1 < n && i - j >= 0; j++)
        {
            if (s[i + j + 1] == s[i - j])
            {
                if (2 * (j + 1) > ans)
                {
                    ans = 2 * (j + 1);
                    idx = i - j;
                }
            }
            else
            {
                break;
            }
        }
    }
    cout << s.substr(idx, ans);
}