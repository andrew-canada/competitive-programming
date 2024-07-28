#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7, numC = 26;

int main()
{
    string n, h;
    cin >> n >> h;
    int nl = n.size(), hl = h.size();
    int mxH = 1;
    for (int i = 0; i < nl - 1; i++)
    {
        mxH = (mxH * numC) % M;
    }
    int nh = 0, hh = 0;
    for (int i = 0; i < nl; i++)
    {
        nh = (nh * numC + (n[i] - 'a' + 1)) % M;
        hh = (hh * numC + (h[i] - 'a' + 1)) % M;
    }
    int ans = 0;
    for (int i = 0; i <= hl - nl; i++)
    {
        if (nh == hh)
        {
            bool found = true;
            for (int j = 0; j < nl; j++)
            {
                if (n[j] != h[i + j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                ans++;
            }
        }
        if (i < hl - nl)
        {
            hh = ((hh - (h[i] - 'a' + 1) * mxH) * mxH + (h[i + nl] - 'a' + 1)) % M;
            if (hh < 0)
            {
                hh += M;
            }
        }
    }
    cout << ans;
}