#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <math.h>
#include <deque>
using namespace std;
void zrob()
{
    long long n, k;
    cin >> n >> k;
    if (k > ((long long)1 << (long long)(min(n - 1, (long long)60))))
    {
        cout << "-1\n";
        return;
    }
    vector<int> perm(n, 0);
    int idx = 0;
    k--;
    while (k != 0)
    {
        if (k % 2 == 1)
            perm[n - 2 - idx] = 1;
        k >>= 1;
        idx++;
    }
    deque<int> odp;
    odp.push_back(n);
    for (int i = n - 2; i != -1; i--)
    {
        if (perm[i] == 1)
            odp.push_back(i + 1);
        else
            odp.push_front(i + 1);
    }
    for (auto i : odp)
        cout << i << ' ';
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testy;
    cin >> testy;
    while (testy--)
    {
        zrob();
    }
    return 0;
}