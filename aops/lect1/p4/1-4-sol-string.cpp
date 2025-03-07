#include <bits/stdc++.h>
using namespace std;

string O_SUB = "OO";

// check that all Gs come before all Hs
bool done(string s, int slen) {
  bool seen_h = false;
  for (int i = 0; i < slen; ++i) {
    if (s[i] == 'O') {
      continue;
    } else if (s[i] == 'G') {
      if (seen_h) {
        return false;
      }
    } else {
      seen_h = true;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; ++tt) {
    int n;
    cin >> n;
    string curr;
    cin >> curr;
    int slen = curr.length();
    if (done(curr, slen)) {
      cout << "0\n";
      continue;
    }
    int o_index = 0;
    while (curr[o_index] != 'O') {
      o_index++;
    }
    vector<pair<string, int> > to_explore;
    to_explore.push_back(make_pair(curr, o_index));
    set<string> seen;
    seen.insert(curr);
    int moves = 0;
    string sub, next;
    bool found_answer = false;
    while (!to_explore.empty()) {
      moves++;
      vector<pair<string, int> > new_to_explore;
      for (int x = 0; x < to_explore.size(); ++x) {
        curr = to_explore[x].first;
        o_index = to_explore[x].second;
        for (int i = 0; i < slen - 1; ++i) {
          if (i == o_index) { // only caught when OO is at the front
            i += 1; // skip the other O too
            continue;
          } else if (i + 1 == o_index) {
            i += 2; // skip this and both positions of the OO
            continue;
          }
          sub = curr.substr(i, 2);
          if (i < o_index) {
            next = curr.substr(0, i) + O_SUB + curr.substr(i + 2, o_index - i - 2) + sub + curr.substr(o_index + 2, slen - o_index - 2);
          } else {
            next = curr.substr(0, o_index) + sub + curr.substr(o_index + 2, i - o_index - 2) + O_SUB + curr.substr(i + 2, slen - i - 2);
          }
          if (seen.find(next) == seen.end()) {
            if (done(next, slen)) {
              cout << moves << '\n';
              found_answer = true;
              break;
            }
            seen.insert(next);
            new_to_explore.push_back(make_pair(next, i));
          }
        }
        if (found_answer) {
          break;
        }
      }
      if (found_answer) {
        break;
      }
      swap(to_explore, new_to_explore);
    }
    if (found_answer) {
      continue;
    }
    cout << "IMPOSSIBLE" << '\n';
  }
}