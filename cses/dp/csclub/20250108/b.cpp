#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int loops = 0;
    vector<string> answers;

    cin >> loops;

    for (int i = 0; i < loops; i++)
    {
        int fences = -1;
        int height = -1;
        vector<int> grounds;

        cin >> fences >> height;

        for (int i = 0; i < fences; i++)
        {
            int x = 0;
            cin >> x;
            grounds.push_back(x);
        }

        for (int j = 0; i < grounds.size(); j++)
        {
        }
    }

    return 0;
}