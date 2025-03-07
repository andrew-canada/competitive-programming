#include <bits/stdc++.h>
using namespace std;

bool check(vector<pair<double, double>> *points,
           vector<pair<double, double>> *centers)
{
    int num_points = points->size();
    int num_centers = centers->size();
    if (num_centers > num_points)
    {
        return false;
    }
    // Check that the circles cover all the points.
    set<int> points_covered;
    for (auto &c : *centers)
    {
        double cx = c.first;
        double cy = c.second;
        for (int i = 0; i < num_points; ++i)
        {
            double px = points->at(i).first;
            double py = points->at(i).second;
            double dx = cx - px;
            double dy = cy - py;
            double dist = sqrt(dx * dx + dy * dy);
            // We're not being too careful with precision here, since this is
            //    just a rough checker. In fact, we'll err on the side of
            //    leniency.
            if (dist <= 0.500000001)
            {
                // This circle covers this point.
                points_covered.insert(i);
            }
        }
    }
    if ((int)(points_covered.size()) < num_points)
    {
        // Not all points were covered.
        return false;
    }
    // Now check that no two circles overlap.
    for (int i = 0; i < num_centers; ++i)
    {
        double cx1 = centers->at(i).first;
        double cy1 = centers->at(i).second;
        for (int j = i + 1; j < num_centers; ++j)
        {
            double cx2 = centers->at(j).first;
            double cy2 = centers->at(j).second;
            double dx = cx2 - cx1;
            double dy = cy2 - cy1;
            double dist = sqrt(dx * dx + dy * dy);
            // The circles should be one diameter's worth apart.
            // Again, we'll be a bit lenient here.
            if (dist <= 0.999999999)
            {
                return false;
            }
        }
    }
    return true;
}