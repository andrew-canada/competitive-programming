#include <bits/stdc++.h>

using namespace std;

const int mxA = 1e6;

int h, curH, k;
vector<int> house;
bool connected[1001];

bool connectAll(int len)
{
    memset(connected, 0, sizeof(connected));
    int remH = h, remK = k;
    for (int i = 0; i < house.size() && remH && remK; i++)
    {
        if (connected[i])
        {
            continue;
        }
        remH--, remK--;
        for (int j = i + 1; j < house.size(); j++)
        {
            int dist = min(house[j] - house[i], house[i] + mxA - house[j]);
            if (!connected[j] && dist <= 2 * len)
            {
                connected[j] = true;
                remH--;
            }
        }
    }
    if (remH == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> h;
    for (int i = 0; i < h; i++)
    {
        cin >> curH;
        house.push_back(curH);
    }
    cin >> k;
    int low = 0, high = mxA;
    sort(house.begin(), house.end());
    if (k >= h)
    {
        cout << 0;
        return 0;
    }
    int ans;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (connectAll(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;
}