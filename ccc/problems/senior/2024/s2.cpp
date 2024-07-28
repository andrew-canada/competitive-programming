#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e6;

int freq[200];

int main()
{
    int t, n;
    cin >> t >> n;
    string s;
    while (t--)
    {
        memset(freq, 0, sizeof(freq));
        cin >> s;
        for (char c : s)
        {
            freq[c]++;
        }
        bool valid = true;
        for (int i = 0; i < s.size() - 1; i++)
        {
            // cout << freq[s[i]] << " " << freq[s[i + 1]] << '\n';
            if (freq[s[i]] == 1)
            {
                if (freq[s[i + 1]] == 1)
                {
                    // cout << "a\n";
                    valid = false;
                    break;
                }
            }
            else
            {
                if (freq[s[i + 1]] > 1)
                {
                    // cout << "b\n";
                    valid = false;
                    break;
                }
            }
        }
        if (valid)
        {
            cout << "T\n";
        }
        else
        {
            cout << "F\n";
        }
    }
}