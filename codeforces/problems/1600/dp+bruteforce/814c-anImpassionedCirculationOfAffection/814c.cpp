#include <bits/stdc++.h>

using namespace std;

const int mxN = 1500;
const int mxQ = 2e5;

int maxLength[26][mxN + 1];

void preprocess(const string &s, int n)
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        for (int m = 0; m <= n; m++)
        {
            int maxLen = 0, left = 0, right = 0, repaint = 0;
            while (right < n)
            {
                if (s[right] != c)
                {
                    ++repaint;
                }
                while (repaint > m)
                {
                    if (s[left] != c)
                    {
                        --repaint;
                    }
                    ++left;
                }
                maxLen = max(maxLen, right - left + 1);
                ++right;
            }
            maxLength[c - 'a'][m] = maxLen;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    string s;
    cin >> n >> s >> q;

    preprocess(s, n);

    while (q--)
    {
        int m;
        char c;
        cin >> m >> c;
        cout << maxLength[c - 'a'][m] << '\n';
    }
}