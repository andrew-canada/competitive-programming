#include <bits/stdc++.h>
using namespace std;

#define MAX_Q 5000

int arr[MAX_Q];
int arr_size = 0;

int get_parent(int idx) {
  return (idx - 1) / 2;
}

int get_left_child(int idx) {
  return 2 * idx + 1;
}

int get_right_child(int idx) {
  return 2 * idx + 2;
}

void add(int v) {
  arr[arr_size] = v;
  int idx = arr_size;
  arr_size++;
  while (true) {
    if (idx == 0) {
      return;
    }
    int parent_idx = get_parent(idx);
    if (arr[idx] < arr[parent_idx]) {
      return;
    }
    swap(arr[idx], arr[parent_idx]);
    idx = parent_idx;
  }
}

void delete_max() {
  arr[0] = arr[arr_size - 1];
  arr_size--;
  int idx = 0;
  while (true) {
    // Start this off with the parent -- we need at least one child's value
    // to exceed the parent's value if we're going to do a swap.
    int bigger_child_idx = idx;
    int lc_idx = get_left_child(idx);
    if (lc_idx < arr_size && arr[lc_idx] > arr[bigger_child_idx]) {
      bigger_child_idx = lc_idx;
    }
    int rc_idx = get_right_child(idx);
    if (rc_idx < arr_size && arr[rc_idx] > arr[bigger_child_idx]) {
      bigger_child_idx = rc_idx;
    }
    if (bigger_child_idx == idx) {
      break;
    }
    swap(arr[idx], arr[bigger_child_idx]);
    idx = bigger_child_idx;
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int q, v;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> v;
    if (v == 0) {
      delete_max();
    } else {
      add(v);
    }
    for (int j = 0; j < arr_size; ++j) {
      cout << arr[j];
      if (j != arr_size - 1) {
        cout << " ";
      }
    }
    cout << "\n";
  }
}