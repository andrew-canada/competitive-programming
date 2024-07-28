#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int idx = upper_bound(arr.begin(), arr.end(), k) - arr.begin();
        if (idx < arr.size())
        {
            arr[idx] = k;
        }
        else
        {
            arr.push_back(k);
        }
    }
    cout << arr.size();
}