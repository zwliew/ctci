/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "circlecross"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, q;
  cin >> n >> q;
  vector<int64_t> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  partial_sum(a.begin(), a.end(), a.begin());

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << a[r] - a[l] << '\n';
  }
}
