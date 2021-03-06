/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  vector<int> c(5);
  for (int i = 0; i < 5; ++i) {
    cin >> c[i];
  }

  int total = accumulate(c.begin(), c.end(), 0);
  if (total % 5 || !total) {
    cout << -1;
    return 0;
  }

  cout << total / 5;
}
