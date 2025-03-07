#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    vector<short> v = {1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    do
    {
        if (v[10] != 15 && v[11] != 15 && v[12] != 15 && v[13] != 15)
        {
            break;
        }
        if (v[0] == abs(v[1] - v[2]) &&
            v[1] == abs(v[3] - v[4]) &&
            v[2] == abs(v[4] - v[5]) &&
            v[3] == abs(v[6] - v[7]) &&
            v[4] == abs(v[7] - v[8]) &&
            v[5] == abs(v[8] - v[9]) &&
            v[6] == abs(v[10] - v[11]) &&
            v[7] == abs(v[11] - v[12]) &&
            v[8] == abs(v[12] - 3) &&
            v[9] == abs(3 - v[13]))
        {
            for (int i : v)
            {
                cout << i << " ";
            }
            cout << '\n';
        }
    } while (next_permutation(v.begin(), v.end()));
}