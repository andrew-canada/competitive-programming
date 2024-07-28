#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxX = 1e6, M = 1e9 + 7;

int freq[mxX + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= mxX; i++)
    {
        for (int j = i; j <= mxX; j += i)
        {
            freq[j]++;
        }
    }
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        cout << freq[x] << '\n';
    }
}