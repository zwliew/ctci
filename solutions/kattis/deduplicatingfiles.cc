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

  int n;
  while (cin >> n && n) {
    unordered_map<char, int> hashCnt;
    unordered_map<string, int> seenCnt;
    string s;
    getline(cin, s);
    int collisions = 0;
    while (n--) {
      getline(cin, s);
      char hash = 0;
      for (char c : s) {
        hash ^= c;
      }
      collisions += hashCnt[hash] - seenCnt[s];
      hashCnt[hash]++;
      seenCnt[s]++;
    }
    cout << seenCnt.size() << " " << collisions << "\n";
  }
}
