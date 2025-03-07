#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> square_list;
    int x_sq = 0;
    int diff_x = 1;
    while (x_sq < n)
    {
        x_sq += diff_x;
        square_list.push_back(x_sq);
        diff_x += 2;
    }

    // one
    if (x_sq == n)
    {
        cout << x_sq << '\n';
        exit(0);
    }

    map<int, pair<int, int>> sum_of_squares_map;
    for (int xi = 0; xi < square_list.size(); ++xi)
    {
        int x_sq = square_list[xi];
        for (int yi = xi; yi < square_list.size(); ++yi)
        {
            // TODO: I think there's a way to enumerate these more efficiently,
            // taking advantage of patterns?
            int y_sq = square_list[yi];
            int sq_sum = x_sq + y_sq;
            if (sq_sum > n)
            {
                break;
            }
            if (sum_of_squares_map.find(sq_sum) == sum_of_squares_map.end())
            {
                // The first way we find to make this value is lexicographically best.
                sum_of_squares_map[sq_sum] = make_pair(x_sq, y_sq);
            }
        }
    }

    // two
    if (sum_of_squares_map.find(n) != sum_of_squares_map.end())
    {
        auto p = sum_of_squares_map[n];
        cout << p.first << " " << p.second << '\n';
        exit(0);
    }

    // Check for sum of three squares
    int trio[3];
    for (int i = 0; i < 3; ++i)
    {
        trio[i] = n;
    }
    int cand_trio[3];
    for (int single : square_list)
    {
        int target = n - single;
        if (sum_of_squares_map.find(target) != sum_of_squares_map.end())
        {
            auto &p = sum_of_squares_map[target];
            cand_trio[0] = min(single, p.first);
            cand_trio[2] = max(single, p.second); // use sortedness of pair
            cand_trio[1] = n - cand_trio[0] - cand_trio[2];
            if ((cand_trio[0] < trio[0]) ||
                ((cand_trio[0] == trio[0]) && (cand_trio[1] < trio[1])))
            {
                for (int i = 0; i < 3; ++i)
                {
                    trio[i] = cand_trio[i];
                }
            }
        }
    }
    if (trio[0] != n)
    {
        cout << trio[0] << " " << trio[1] << " " << trio[2] << '\n';
        exit(0);
    }
    // OK, it has to be a sum of four squares! Do pretty much the same thing as
    // above.
    int tetrad[4];
    for (int i = 0; i < 4; ++i)
    {
        tetrad[i] = n;
    }
    int cand_tetrad[4];
    for (auto &p1 : sum_of_squares_map)
    {
        int target = n - p1.first;
        if (target < p1.first)
        {
            break;
        }
        if (sum_of_squares_map.find(target) != sum_of_squares_map.end())
        {
            auto &p2 = sum_of_squares_map[target];
            // TODO: can we be more clever here than sorting? does it matter?
            cand_tetrad[0] = p1.second.first;
            cand_tetrad[1] = p1.second.second;
            cand_tetrad[2] = p2.first;
            cand_tetrad[3] = p2.second;
            sort(cand_tetrad, cand_tetrad + 4);
            if ((cand_tetrad[0] < tetrad[0]) ||
                ((cand_tetrad[0] == tetrad[0]) && (cand_tetrad[1] < tetrad[1])) ||
                ((cand_tetrad[0] == tetrad[0]) && (cand_tetrad[1] == tetrad[1]) && (cand_tetrad[2] < tetrad[2])))
            {
                for (int i = 0; i < 4; ++i)
                {
                    tetrad[i] = cand_tetrad[i];
                }
            }
        }
    }
    cout << tetrad[0] << " " << tetrad[1] << " " << tetrad[2] << " " << tetrad[3] << '\n';
}