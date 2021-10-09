// clang-format off
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, m, n) for (int i = m; i < (int)(n); i++)
#define repe(i, m, n) for (int i = m; i <= (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using vvi = vector<vector<int>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// clang-format on

// 二部グラフ判定(UnionFind)
// https://noshi91.hatenablog.com/entry/2018/04/17/183132
bool is_bipartite(const vvi &G) {
  int n = G.size();
  dsu D(n * 2);
  rep(i, 0, n) {
    for (int v : G[i]) {
      D.merge(i, v + n);
    }
  }
  rep(i, 0, n) {
    if (D.same(i, i + n)) return false;
  }
  return true;
}

// グラフ作成
vvi make_graph() {
  int n, m;
  cin >> n >> m;
  vvi G(n);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  return G;
}

// DSU作成
dsu make_dsu(const vvi &G) {
  int n = G.size();
  dsu D(n);
  rep(i, 0, n) {
    for (int v : G[i]) {
      D.merge(i, v);
    }
  }
  return D;
}

int main() {
  auto G = make_graph();
  auto dsu = make_dsu(G);

  cout << dsu.groups().size() << endl;

  // cout << (is_bipartite(G) ? "Yes" : "No") << endl;
}