
struct Edge {
  int u;
  int v;
  int w;

  Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}

  bool operator<(const Edge& x) { return w < x.w; }
};

#include <queue>
#include <vector>
struct Graph {
  int n;
  std::vector<std::vector<Edge>> adj;

  Graph(int _n) : n(_n) { adj = std::vector<std::vector<Edge>>(n); }

  void addEdge(int u, int v, int w) { adj[u].emplace_back(u, v, w); }

  void addEdge(Edge& e) { adj[e.u].emplace_back(e); }

  std::vector<int> bfs(int start) {
    std::queue<int> q;
    std::vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    q.emplace(start);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (auto& e : adj[u]) {
        if (dist[e.v] > dist[u] + e.w) {
          dist[e.v] = dist[u] + e.w;
          q.emplace(e.v);
        }
      }
    }
    return dist;
  }
};

struct Tree : Graph {
  int diameter() {
    auto dist = bfs(0);
    int start = distance(dist.begin(), max_element(dist.begin(), dist.end()));
    dist = bfs(start);
    return *max_element(dist.begin(), dist.end());
  }
};