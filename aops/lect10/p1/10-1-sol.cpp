#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pt;

bool points_ccw(pt pt1, pt pt2, pt pt3)
{
    return ((pt3.second - pt1.second) * (pt2.first - pt1.first)) > ((pt2.second - pt1.second) * (pt3.first - pt1.first));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll xi, yi;
    cin >> n;
    vector<pt> pts;
    for (int i = 0; i < n; ++i)
    {
        cin >> xi >> yi;
        pts.push_back(make_pair(xi, yi));
    }
    // find leftmost point
    int i = 0;
    for (int j = 1; j < n; ++j)
    {
        if ((pts[j].first < pts[i].first) ||
            ((pts[j].first == pts[i].first) && (pts[j].second < pts[i].second)))
        {
            i = j;
        }
    }
    vector<int> hull;
    hull.push_back(i);
    set<int> non_hull; // but we leave i in since we need to return to it
    for (int j = 0; j < n; ++j)
    {
        non_hull.insert(j);
    }
    int most_recent_point = i;
    int next_candidate;
    while (true)
    {
        next_candidate = (most_recent_point == 0 ? 1 : 0);
        for (int j : non_hull)
        {
            if ((j == most_recent_point) || (j == next_candidate))
            {
                continue;
            }
            // Is this new point to the left or right of the line from the
            //   most recent hull point to the current candidate?
            if (points_ccw(pts[most_recent_point],
                           pts[next_candidate], pts[j]))
            {
                next_candidate = j;
            }
        }
        if (next_candidate == hull[0])
        {
            break;
        }
        hull.push_back(next_candidate);
        non_hull.erase(next_candidate);
        most_recent_point = next_candidate;
    }
    cout << (2 * n - hull.size() - 2) << '\n';
}
