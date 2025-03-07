#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    vector<int> v = {1, 2, 3, 4, 5, 6};
    do
    {
        if (v[0] == abs(v[1] - v[2]) &&
            v[1] == abs(v[3] - v[4]) &&
            v[2] == abs(v[4] - v[5]))
        {
            for (int i : v)
            {
                cout << i << " ";
            }
            cout << '\n';
        }
    } while (next_permutation(v.begin(), v.end()));
}