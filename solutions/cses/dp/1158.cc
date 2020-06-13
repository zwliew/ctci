#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;
  vector<int> h(n), s(n);
  for (int &i : h) cin >> i;
  for (int &i : s) cin >> i;
  vector<vector<int>> maxPages(n + 1, vector<int>(x + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= x; ++j) {
      maxPages[i][j] =
          max(maxPages[i - 1][j],
              (j >= h[i - 1] ? maxPages[i - 1][j - h[i - 1]] + s[i - 1] : 0));
    }
  }
  cout << maxPages[n][x];
}