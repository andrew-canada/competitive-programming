#include <bits/stdc++.h>
using namespace std;

const int GRANULARITY = 1000000000;

bool contains(double ctr_x, double ctr_y, double pt_x, double pt_y)
{
    double t1 = ctr_x - pt_x;
    double t2 = ctr_y - pt_y;
    // within a radius of 1/2
    return (t1 * t1 + t2 * t2) <= 0.25; // comparing squared distances
}

int main()
{
    int g;
    cin >> g;
    double xi, yi;
    vector<pair<double, double>> points;
    for (int i = 0; i < g; ++i)
    {
        cin >> xi >> yi;
        points.push_back(make_pair(xi, yi));
    }
    srand(12345);
    set<pair<double, double>> answer;
    while (true)
    {
        answer.clear();
        double x_offset = (rand() % GRANULARITY) / (double)GRANULARITY;
        double y_offset = (rand() % GRANULARITY) / (double)GRANULARITY;
        bool ok = true;
        for (auto &p : points)
        {
            double pt_x = p.first;
            double pt_y = p.second;
            bool found_point = false;
            // Check all the circles that could contain this.
            int x = (int)(pt_x);
            int y = (int)(pt_y);
            // Try the 9 surrounding circles just in case.
            for (int xx = x - 1; xx <= x + 1; ++xx)
            {
                for (int yy = y - 1; yy <= y + 1; ++yy)
                {
                    double ctr_x = (double)xx + x_offset;
                    double ctr_y = (double)yy + y_offset;
                    if (contains(ctr_x, ctr_y, pt_x, pt_y))
                    {
                        answer.insert(make_pair(ctr_x, ctr_y));
                        found_point = true;
                        break;
                    }
                }
                if (found_point)
                {
                    break;
                }
            }
            if (!found_point)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            continue;
        }
        break;
    }
    cout << "POSSIBLE\n";
    for (auto &p : answer)
    {
        cerr << fixed << setprecision(9) << p.first << " " << p.second << '\n';
    }
}