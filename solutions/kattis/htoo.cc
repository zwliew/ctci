#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
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

  string molecule;
  int n;
  cin >> molecule >> n;
  array<int, 26> have, want;
  auto fillCounts = [&](array<int, 26>& counts, string s) {
    fill(counts.begin(), counts.end(), 0);
    for (int i = 0; i < s.size();) {
      int j = i + 1;
      int cnt = 0;
      while (j < s.size() && isdigit(s[j])) {
        cnt *= 10;
        cnt += s[j] - '0';
        ++j;
      }
      counts[s[i] - 'A'] += max(cnt, 1);
      i = j;
    }
  };
  fillCounts(have, molecule);
  cin >> molecule;
  fillCounts(want, molecule);

  int mx = INT_MAX;
  for (int i = 0; i < 26; ++i) {
    if (!want[i])
      continue;
    mx = min(mx, have[i] * n / want[i]);
  }
  cout << mx;
}
