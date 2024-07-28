#include <bits/stdc++.h>

using namespace std;

const int mxR = 1e3;

int freq[mxR + 1];

int main()
{
    int n;
    scanf("%d", &n);
    int val;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        freq[val]++;
    }
    vector<array<int, 2>> vals;
    for (int i = 1; i <= 1000; i++)
    {
        if (freq[i])
        {
            vals.push_back({freq[i], i});
        }
    }
    sort(vals.begin(), vals.end(), greater<array<int, 2>>());
    // first highest and last second-highest
    set<int> highest, secondHighest;
    int idx;
    for (int i = 0; i < vals.size(); i++)
    {
        if (vals[i][0] == vals[0][0])
        {
            highest.insert(vals[i][1]);
            idx = i + 1;
        }
        else
        {
            idx = i;
            break;
        }
    }
    for (int i = idx; i < vals.size(); i++)
    {
        if (vals[i][0] == vals[idx][0])
        {
            secondHighest.insert(vals[i][1]);
        }
        else
        {
            break;
        }
    }
    if (highest.size() > 1)
    {
        cout << abs(*(highest.begin()) - *(--highest.end()));
        return 0;
    }
    int diff1 = abs(*(highest.begin()) - *(--secondHighest.end()));
    int diff2 = abs(*(--highest.end()) - *(secondHighest.begin()));
    cout << max(diff1, diff2);
}