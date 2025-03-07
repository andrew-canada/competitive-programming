#include <bits/stdc++.h>

using namespace std;

double percent[8] = {0.48, 0.22, 0.11, 0.35, 1.41, 1.41, 5.69, 1.95};
int mass[8] = {42, 43, 78, 80, 82, 83, 84, 86};

int main()
{
    double ans = 0, tot = 0;
    for (int i = 0; i < 8; i++)
    {
        tot += percent[i];
    }
    for (int i = 0; i < 8; i++)
    {
        ans += mass[i] * percent[i] / tot;
    }
    cout << ans;
}