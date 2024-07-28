#include <bits/stdc++.h>

using namespace std;

int arr1[105], arr2[105];

int main()
{
    int type, n;
    cin >> type >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    // min tot
    if (type == 1)
    {
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n);
        int tot = 0;
        for (int i = 0; i < n; i++)
        {
            tot += max(arr1[i], arr2[i]);
        }
        cout << tot;
    }
    // max
    else
    {
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n, greater<int>());
        int tot = 0;
        for (int i = 0; i < n; i++)
        {
            tot += max(arr1[i], arr2[i]);
        }
        cout << tot;
    }
}