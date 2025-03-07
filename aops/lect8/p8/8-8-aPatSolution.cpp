#include <bits/stdc++.h>
using namespace std;

const int digits = 1e9;

array<double, 2> pts[10];
set<array<double, 2>> ans;

bool covered(double cx, double cy, double px, double py)
{
    double dx = cx - px, dy = cy - py;
    return (dx * dx + dy * dy <= 0.25);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand(12345);
    int g;
    double x, y;
    for (int i = 0; i < g; i++)
    {
        cin >> x >> y;
        pts[i] = {x, y};
    }
    while (true)
    {
        ans.clear();
        double xShift = rand() % digits / (double)digits, yShift = rand() % digits / (double)digits;
        bool valid = true;
        for (const auto &p : pts)
        {
            bool found = false;
            int latticeX = (int)p[0], latticeY = (int)p[1];
            for (int x1 = latticeX - 1; x1 <= latticeX + 1; x1++)
            {
                for (int y1 = latticeY - 1; y1 <= latticeY + 1; y1++)
                {
                    double centerX = 1.0 * x1 + xShift, centerY = 1.0 * y1 + yShift;
                    if (covered(centerX, centerY, p[0], p[1]))
                    {
                        ans.insert({centerX, centerY});
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    break;
                }
            }
            if (!found)
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            continue;
        }
        break;
    }
    cout << "POSSIBLE\n";
    for (const auto &a : ans)
    {
        cerr << fixed << setprecision(9) << a[0] << a[1] << '\n';
    }
}