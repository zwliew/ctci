/*
ID: zhaowei10
TASK:
LANG: C++
*/
#include <algorithm>
#include <array>
#include <bitset>
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

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define MOD 1000000007
#define NDIG(x) floor(log10(x)) + 1
#define FOR(i, j, k, l) for (s32 i = j; i < k; i += l)
#define RFOR(i, j, k, l) for (s32 i = j; i >= k; i -= l)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(x) x.begin(), x.end()
#define MEAN(a, b) min(a, b) + (abs(b - a) >> 1)
#define FASTIO()    \
  cin.tie(nullptr); \
  ios::sync_with_stdio(false);

typedef long long ll;
typedef int64_t s64;
typedef uint64_t u64;
typedef int32_t s32;
typedef uint32_t u32;
typedef float f32;
typedef double f64;
typedef long double f80;
typedef pair<s32, s32> II;
typedef pair<s64, s64> LL;
typedef vector<s32> VI;
typedef vector<II> VII;
typedef vector<char> VC;
typedef vector<VII> VVII;
typedef priority_queue<s32> PQI;
typedef priority_queue<s32, VI, greater<s32>> PQIA;
typedef priority_queue<s64> PQL;
typedef priority_queue<II> PQII;
typedef priority_queue<II, VII, greater<II>> PQIIA;
typedef priority_queue<LL> PQLL;
typedef unordered_set<s32> USI;
typedef unordered_set<s64> USL;
typedef set<II> SII;
typedef multiset<s32> MSI;

int findSet(vector<int> &p, int a) {
  return p[a] == a ? a : (p[a] = findSet(p, p[a]));
}

bool sameSet(vector<int> &p, int a, int b) {
  return findSet(p, a) == findSet(p, b);
}

void unionSet(vector<int> &p, int a, int b) {
  p[findSet(p, a)] = findSet(p, b);
}

int main() {
  FASTIO();

  int n, e, p;
  cin >> n >> e >> p;

  vector<pair<f80, f80>> coords(n + 1);
  for (int i = 1; i <= n; ++i) {
    f80 x, y;
    cin >> x >> y;
    coords[i] = mp(x, y);
  }

  vector<int> parents(n + 1);
  iota(parents.begin(), parents.end(), 0);

  for (int i = 2; i <= e; ++i) {
    unionSet(parents, i, i - 1);
  }

  f80 minl = 0;
  for (int i = 0; i < p; ++i) {
    int a, b;
    cin >> a >> b;
    unionSet(parents, a, b);
  }

  vector<tuple<f80, int, int>> edges;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (sameSet(parents, i, j)) continue;
      edges.eb(hypotl(coords[i].first - coords[j].first,
                      coords[i].second - coords[j].second),
               i, j);
    }
  }
  sort(edges.begin(), edges.end());

  for (int i = 0; i < edges.size(); ++i) {
    auto &[l, a, b] = edges[i];
    if (sameSet(parents, a, b)) continue;
    minl += l;
    unionSet(parents, a, b);
  }

  cout << minl;
}