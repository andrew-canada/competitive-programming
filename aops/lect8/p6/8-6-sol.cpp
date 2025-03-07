#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int degrees[n];
    for (int i = 0; i < n; ++i)
    {
        degrees[i] = 0;
    }
    int ui, vi;
    int degree_sum = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> ui >> vi;
        ui--;
        vi--;
        degrees[ui]++;
        degrees[vi]++;
        degree_sum += 2;
    }
    char pi;
    int a_degree_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> pi;
        if (pi == 'A')
        {
            a_degree_sum += degrees[i];
        }
    }
    double answer = (double)a_degree_sum / degree_sum;
    cout << fixed << setprecision(9) << answer << '\n';
}