/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
string to_string(char c) { return string(1, c); }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < v.size(); ++i) {
    res += char('0' + v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> b) {
  string res = "";
  for (int i = 0; i < N; ++i) {
    res += char('0' + b[i]);
  }
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += '}';
  return res;
}

void _debug() { cerr << '\n'; }
template <typename Head, typename... Tail>
void _debug(Head H, Tail... T) {
  cerr << ' ' << to_string(H);
  _debug(T...);
}
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

#define eb emplace_back

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

int h, w;
const vii edges = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool dfs(vector<vc> &grid, vector<vb> &vis, int r, int c, int pr, int pc) {
  vis[r][c] = true;
  for (auto &[dr, dc] : edges) {
    int nr = r + dr;
    int nc = c + dc;
    if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
    if (nr == pr && nc == pc) continue;
    if (grid[r][c] != grid[nr][nc]) continue;
    if (vis[nr][nc]) return true;
    if (dfs(grid, vis, nr, nc, r, c)) return true;
  }
  return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  cin >> h >> w;
  vector<vc> grid(h, vc(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<vb> vis(h, vb(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!vis[i][j]) {
        if (dfs(grid, vis, i, j, -1, -1)) {
          cout << "Yes";
          return 0;
        }
      }
    }
  }

  cout << "No";
}
