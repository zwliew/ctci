#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
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
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ")";
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

#define eb emplace_back

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;

void topoSort(vector<vi> &adj, vb &vis, vi &out, int u) {
  vis[u] = 1;
  for (auto v : adj[u]) {
    if (vis[v]) continue;
    topoSort(adj, vis, out, v);
  }
  out.eb(u);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  int n, k;
  cin >> n >> k;
  vector<vi> adj(n + 1);
  for (int i = 1; i <= k; ++i) {
    int w;
    cin >> w;
    for (int j = 0; j < w; ++j) {
      int v;
      cin >> v;
      adj[i].eb(v);
    }
  }

  vb vis(n + 1);
  vi out;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      topoSort(adj, vis, out, i);
    }
  }
  reverse(out.begin(), out.end());
  debug(out);
  vi ans(n);
  for (int i = 0; i < out.size(); ++i) {
    if (i == 0) {
      ans[out[i] - 1] = 0;
    } else {
      ans[out[i] - 1] = out[i - 1];
    }
  }
  for (auto x : ans) cout << x << '\n';
}
