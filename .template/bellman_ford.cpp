/* bellman_ford(Es,s,t,dis)
    入力: 全ての辺Es, 頂点数V, 開始点 s, 最短経路を記録するdis
    出力: 負の閉路が存在するなら ture
    計算量：O(|E||V|)
    副作用：dis が書き換えられる
*/
bool bellman_ford(const Edges &Es, int V, int s, vector<long long> &dis) {
  dis.resize(V, INF);
  dis[s] = 0;
  int cnt = 0;
  while (cnt < V) {
    bool end = true;
    for (auto e : Es) {
      if (dis[e.from] != INF && dis[e.from] + e.cost < dis[e.to]) {
        dis[e.to] = dis[e.from] + e.cost;
        end = false;
      }
    }
    if (end) break;
    cnt++;
  }
  return (cnt == V);
}