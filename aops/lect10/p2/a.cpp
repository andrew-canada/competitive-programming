#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;
typedef tuple<ll, ll, ll, ll> Segment;

struct Event
{
    ll x;
    int type; // 1 for start, -1 for end
    int index;
    Event(ll x, int type, int index) : x(x), type(type), index(index) {}
    bool operator<(const Event &other) const
    {
        if (x == other.x)
            return type > other.type;
        return x < other.x;
    }
};

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    auto orientation = [](Point p, Point q, Point r)
    {
        ll val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
        if (val == 0)
            return 0;
        return (val > 0) ? 1 : 2;
    };
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && min(p1.first, q1.first) <= p2.first && p2.first <= max(p1.first, q1.first) && min(p1.second, q1.second) <= p2.second && p2.second <= max(p1.second, q1.second))
        return true;
    if (o2 == 0 && min(p1.first, q1.first) <= q2.first && q2.first <= max(p1.first, q1.first) && min(p1.second, q1.second) <= q2.second && q2.second <= max(p1.second, q1.second))
        return true;
    if (o3 == 0 && min(p2.first, q2.first) <= p1.first && p1.first <= max(p2.first, q2.first) && min(p2.second, q2.second) <= p1.second && p1.second <= max(p2.second, q2.second))
        return true;
    if (o4 == 0 && min(p2.first, q2.first) <= q1.first && q1.first <= max(p2.first, q2.first) && min(p2.second, q2.second) <= q1.second && q1.second <= max(p2.second, q2.second))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<Segment> segments(n);
        vector<Event> events;
        for (int i = 0; i < n; i++)
        {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            segments[i] = make_tuple(x1, y1, x2, y2);
            events.emplace_back(x1, 1, i);
            events.emplace_back(x2, -1, i);
        }

        sort(events.begin(), events.end());

        set<int> active_segments;
        bool bad_luck = false;

        for (const auto &event : events)
        {
            int idx = event.index;
            auto [x1, y1, x2, y2] = segments[idx];
            if (event.type == 1)
            {
                for (int active_idx : active_segments)
                {
                    auto [ax1, ay1, ax2, ay2] = segments[active_idx];
                    if (doIntersect({x1, y1}, {x2, y2}, {ax1, ay1}, {ax2, ay2}))
                    {
                        bad_luck = true;
                        break;
                    }
                }
                if (bad_luck)
                    break;
                active_segments.insert(idx);
            }
            else
            {
                active_segments.erase(idx);
            }
        }

        if (bad_luck)
        {
            cout << "BAD LUCK\n";
        }
        else
        {
            cout << "GOOD LUCK\n";
        }
    }

    return 0;
}