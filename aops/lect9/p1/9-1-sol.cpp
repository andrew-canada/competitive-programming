#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll area(vector<ll> rect)
{
    return ((rect[2] - rect[0]) * (rect[3] - rect[1]));
}

vector<ll> overlap(vector<ll> rect1, vector<ll> rect2)
{
    vector<ll> answer = {0, 0, 0, 0};
    ll ll_x1 = rect1[0];
    ll ll_y1 = rect1[1];
    ll ur_x1 = rect1[2];
    ll ur_y1 = rect1[3];
    ll ll_x2 = rect2[0];
    ll ll_y2 = rect2[1];
    ll ur_x2 = rect2[2];
    ll ur_y2 = rect2[3];
    // at the outset, handle the case where they share the same lower left point
    if ((ll_x1 == ll_x2) && (ll_y1 == ll_y2))
    {
        answer[0] = ll_x1;
        answer[1] = ll_y1;
        answer[2] = min(ur_x1, ur_x2);
        answer[3] = min(ur_y1, ur_y2);
        return answer;
    }
    // if necessary, make rectangle 1 be the one with the smaller ll_x
    // or, if tied on ll_x, make  the one with the smaller ll_y
    ll tmp;
    if ((ll_x2 < ll_x1) || ((ll_x1 == ll_x2) && (ll_y2 < ll_y1)))
    {
        tmp = ll_x1;
        ll_x1 = ll_x2;
        ll_x2 = tmp;
        tmp = ll_y1;
        ll_y1 = ll_y2;
        ll_y2 = tmp;
        tmp = ur_x1;
        ur_x1 = ur_x2;
        ur_x2 = tmp;
        tmp = ur_y1;
        ur_y1 = ur_y2;
        ur_y2 = tmp;
    }
    if (ll_x1 == ll_x2)
    {
        // we know ll_y1 < ll_y2 when there's this tie
        if (ll_y2 <= ur_y1)
        {
            answer[0] = ll_x1;
            answer[1] = ll_y2;
            answer[2] = min(ur_x1, ur_x2);
            answer[3] = min(ur_y1, ur_y2);
            return answer;
        }
        else
        {
            return answer; // no overlap
        }
    }
    // now we know ll_x1 < ll_x2
    if (ll_x2 >= ur_x1)
    {
        return answer; // no overlap
    }
    // and now we know ll_x1 < ll_x2 < ur_x1
    if (ll_y2 <= ll_y1)
    {
        if (ll_y1 < ur_y2)
        {
            answer[0] = ll_x2;
            answer[1] = ll_y1;
            answer[2] = min(ur_x1, ur_x2);
            answer[3] = min(ur_y1, ur_y2);
            return answer;
        }
        else
        {
            return answer; // no overlap
        }
    }
    // now we have ll_x1 < ll_x2 < ur_x1 and ll_y1 < ll_y2
    if (ll_y2 < ur_y1)
    {
        // then ll_x1 < ll_x2 < ur_x1 and ll_y1 < ll_y2 < ur_y1
        answer[0] = ll_x2;
        answer[1] = ll_y2;
        answer[2] = min(ur_x1, ur_x2);
        answer[3] = min(ur_y1, ur_y2);
        return answer;
    }
    else
    {
        return answer; // no overlap
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    ll li, di, ri, ui;
    cin >> n;
    vector<vector<ll>> rects;
    for (int i = 0; i < n; ++i)
    {
        cin >> li >> di >> ri >> ui;
        vector<ll> v = {li, di, ri, ui};
        rects.push_back(v);
    }
    map<vector<int>, vector<ll>> precomp;
    if (n >= 5)
    {
        for (int a = 0; a < n; ++a)
        {
            vector<int> v = {a};
            precomp[v] = rects[a];
            for (int b = a + 1; b < n; ++b)
            {
                vector vv = {a, b};
                precomp[vv] = overlap(precomp[v], rects[b]);
                for (int c = b + 1; c < n; ++c)
                {
                    vector vvv = {a, b, c};
                    precomp[vvv] = overlap(precomp[vv], rects[c]);
                    for (int d = c + 1; d < n; ++d)
                    {
                        vector vvvv = {a, b, c, d};
                        precomp[vvvv] = overlap(precomp[vvv], rects[d]);
                        for (int e = d + 1; e < n; ++e)
                        {
                            vector vvvvv = {a, b, c, d, e};
                            precomp[vvvvv] = overlap(precomp[vvvv], rects[e]);
                        }
                    }
                }
            }
        }
    }
    vector<ll> all = {-INT_MAX, -INT_MAX, INT_MAX, INT_MAX};
    vector<ll> combined;
    ll total_area = 0;
    int poss = 1 << n;
    // Start at 1 to exclude the possibility where we have NO overlap.
    for (int i = 1; i < poss; ++i)
    {
        int j = i;
        combined = all;
        vector<int> indices;
        for (int k = 0; k < n; ++k)
        {
            if (j % 2 == 1)
            {
                indices.push_back(k);
            }
            j /= 2;
        }
        int sz = indices.size();
        int sign = ((sz % 2 == 1) ? 1 : -1);
        if (n < 5)
        {
            for (int idx : indices)
            {
                combined = overlap(combined, rects[idx]);
            }
        }
        else
        {
            for (int block = 0; 5 * block < sz; ++block)
            {
                vector<int> subindices;
                for (int sidx = 5 * block; sidx < min(sz, 5 * (block + 1)); ++sidx)
                {
                    subindices.push_back(indices[sidx]);
                }
                combined = overlap(combined, precomp[subindices]);
                if (area(combined) == 0)
                {
                    break;
                }
            }
        }
        total_area += (sign * area(combined));
    }
    cout << total_area << '\n';
}