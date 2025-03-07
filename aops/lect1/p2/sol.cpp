#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

const int MAX_X = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  priority_queue <tuple<int, int, int>> events;
  priority_queue <pi> barns;

  int l, r, h;
  for (int i = 0; i < n; i++) {
    cin >> l >> r >> h;
    events.emplace(-l, -r, h);
  }

  barns.emplace(0, -MAX_X - 1);

  ll area = 0, prev_height;
  int prev_loc = 0, cur;
  while (!events.empty()) {
    auto [cur, r, h] = events.top();
    events.pop();
    prev_height = barns.top().first;

    if (h > 0) {
      // entry event
      barns.emplace(h, r);
      events.emplace(r, 0, 0);
    } else {
      // exit event, clear out stale stuff in barns PQ
      while (barns.top().second >= cur) barns.pop();
    }
    area += prev_height * (prev_loc - cur);
    prev_loc = cur;
  }

  cout << area << '\n';

  return 0;
}