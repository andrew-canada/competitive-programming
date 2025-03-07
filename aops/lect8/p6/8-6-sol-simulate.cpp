#include <bits/stdc++.h>
using namespace std;

// Returns true if the system converges on A, and false if it converges on B.
bool sim(int n, vector<vector<int>> *neighs, vector<bool> *initial_prefs)
{
    bool prefs[2][n];
    for (int i = 0; i < n; ++i)
    {
        prefs[0][i] = initial_prefs->at(i);
    }
    int which_next = 1;
    while (true)
    {
        for (int i = 0; i < n; ++i)
        {
            if (rand() % 2)
            { // don't change
                prefs[which_next][i] = prefs[1 - which_next][i];
            }
            else
            {
                // choose a random neighbor
                int which_neigh = rand() % neighs->at(i).size();
                prefs[which_next][i] = prefs[1 - which_next][neighs->at(i)[which_neigh]];
            }
        }
        // see if we've converged
        bool first = prefs[which_next][0];
        bool converged = true;
        for (int i = 1; i < n; ++i)
        {
            if (prefs[which_next][i] != first)
            {
                converged = false;
                break;
            }
        }
        if (converged)
        {
            return first;
        }
        which_next = 1 - which_next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(12345);
    int n, m;
    cin >> n >> m;
    int ui, vi;
    vector<vector<int>> neighs;
    for (int i = 0; i < n; ++i)
    {
        vector<int> v;
        neighs.push_back(v);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> ui >> vi;
        ui--;
        vi--;
        neighs[ui].push_back(vi);
        neighs[vi].push_back(ui);
    }
    vector<bool> initial_prefs;
    char pi;
    for (int i = 0; i < n; ++i)
    {
        cin >> pi;
        initial_prefs.push_back(pi == 'A');
    }
    int total_a = 0;
    for (int i = 0; i < 1000; ++i)
    {
        if (sim(n, &neighs, &initial_prefs))
        {
            total_a++;
        }
    }
    double answer = (double)total_a / 100;
    answer = round(answer);
    answer /= 10;
    cout << fixed << setprecision(9) << answer << '\n';
}