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

#define LOCAL
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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

  int n;
  cin >> n;
  vi c(n);
  for (int &x : c) {
    cin >> x;
  }

  vector<vector<ll>> numWays(30001, vector<ll>(n + 1));
  fill(numWays[0].begin(), numWays[0].end(), 1);
  for (int i = 1; i <= 30000; ++i) {
    for (int j = 1; j <= n; ++j) {
      numWays[i][j] = numWays[i][j - 1];
      if (i >= c[j - 1]) {
        numWays[i][j] += numWays[i - c[j - 1]][j];
      }
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    if (numWays[x][n] == 0) {
      cout << "Impossible\n";
    } else if (numWays[x][n] > 1) {
      cout << "Ambiguous\n";
    } else {
      int cur = x;
      int i = n;
      vi output;
      while (cur != 0) {
        if (i >= 1 && numWays[cur][i - 1] == numWays[cur][i]) {
          --i;
        } else {
          cur -= c[i - 1];
          output.emplace_back(i);
        }
      }
      for (int i = output.size() - 1; i >= 0; --i) {
        cout << output[i] << ' ';
      }
      cout << '\n';
    }
  }
}