#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

// We will represent Gs and Os as 0, and Hs as 1.
// Os need to be 0 because we use a set to see where we've been, so we
// can't leave arbitrary garbage there.
// The whole thing is stored in the final bits of an unsigned long long.

// traverse right to left, we'd better see all Hs before all Gs
bool done(pair<ui, int> p, int len)
{
    ui state = p.first;
    int oo_index = (int)p.second;
    bool seen_g = false;
    int i = len - 1;
    while (i >= 0)
    {
        if (i == oo_index + 1)
        {
            state >>= 1; // extra so we skip over the whole index
            i -= 1;      // same
        }
        else if (state % 2 == 1)
        {
            if (seen_g)
            {
                return false;
            }
        }
        else
        {
            seen_g = true;
        }
        i -= 1;
        state >>= 1;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt)
    {
        int n;
        cin >> n;
        string curr_s;
        cin >> curr_s;
        int len = curr_s.length();
        ui curr = 0;
        int i = 0;
        int oo_index;
        while (i < len)
        {
            if (curr_s[i] == 'O')
            {
                oo_index = i;
                curr <<= 1; // extra to skip the other O
                i += 1;     // same
            }
            else if (curr_s[i] == 'H')
            {
                curr += 1;
            } // if it's a G, we'd put in a 0, so we do nothing
            curr <<= 1;
            i += 1;
        }
        curr >>= 1; // since the loop did one extra shift at the end
        pair<ui, int> curr_pair = make_pair(curr, oo_index);
        if (done(curr_pair, len))
        {
            cout << "0\n";
            continue;
        }
        vector<pair<ui, int>> to_explore;
        to_explore.push_back(curr_pair);
        set<pair<ui, int>> seen;
        seen.insert(curr_pair);
        int num_moves = 0;
        bool found_answer = false;
        while (!to_explore.empty())
        {
            num_moves++;
            vector<pair<ui, int>> new_to_explore;
            for (auto &curr_pair : to_explore)
            {
                curr = curr_pair.first;
                oo_index = (int)curr_pair.second;
                // Look through all possible NEW locations for the OO
                for (int i = 0; i < len - 1; ++i)
                {
                    if (i == oo_index)
                    {           // only caught when OO is at the front
                        i += 1; // skip the other O too (the for loop will add the add'l 1)
                        continue;
                    }
                    else if (i + 1 == oo_index)
                    {
                        i += 2; // skip this and both positions of the OO
                        continue;
                    }
                    // time for a bunch of horrid bit manipulation that is hopefully
                    // faster than the string versions thereof
                    ui sub_template = 3; // 0...011
                    sub_template <<= (len - i - 2);
                    ui reverse_sub_template = 0;
                    for (int j = 0; j < len; ++j)
                    {
                        if ((j != i) && (j != i + 1))
                        {
                            reverse_sub_template++;
                        }
                        reverse_sub_template <<= 1;
                    }
                    reverse_sub_template >>= 1;
                    ui oo_template = 3;
                    oo_template <<= (len - oo_index - 2);
                    ui reverse_oo_template = 0;
                    for (int j = 0; j < len; ++j)
                    {
                        if ((j != oo_index) && (j != oo_index + 1))
                        {
                            reverse_oo_template++;
                        }
                        reverse_oo_template <<= 1;
                    }
                    reverse_oo_template >>= 1;
                    ui sub = sub_template & curr; // grab the substring (rest are 0s)
                    // Move this substring to the correct place.
                    sub >>= (len - i - 2);
                    sub <<= (len - oo_index - 2); // TODO: combine these two lines?
                    // cout << "sub is now " << sub << '\n';
                    ui next = curr;
                    // wipe out whatever garbage is at oo_index, leave the rest the same
                    next &= reverse_oo_template;
                    // put the moved substring there
                    next |= sub;
                    // cout << "reverse sub template is " << reverse_sub_template << '\n';
                    // Wipe out whatever's at the old sub location.
                    next &= reverse_sub_template;
                    pair<ui, int> next_pair = make_pair(next, i); // i is new oo_index
                    // cout << "curr: " << curr << " " << oo_index << " next: " << next << " " << i << '\n';
                    if (seen.find(next_pair) == seen.end())
                    {
                        if (done(next_pair, len))
                        {
                            cout << num_moves << '\n';
                            found_answer = true;
                            break;
                        }
                        seen.insert(next_pair);
                        new_to_explore.push_back(next_pair);
                    }
                }
                if (found_answer)
                {
                    break;
                }
            }
            if (found_answer)
            {
                break;
            }
            swap(to_explore, new_to_explore);
        }
        if (found_answer)
        {
            continue;
        }
        cout << "IMPOSSIBLE" << '\n';
    }
}