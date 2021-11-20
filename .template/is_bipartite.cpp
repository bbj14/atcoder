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