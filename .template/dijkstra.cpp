/* dijkstra(G,s,dis)
  input: G:グラフ, s:開始点, dis:sからの距離
  output: prev:最短経路の前の点
  計算量: O(|E|log|V|)
*/
VI dijkstra(const VV<PII> &G, int s, VI &dis) {
  int N = G.size();
  dis.resize(N, 1LL << 60);
  VI prev(N, -1);
  priority_queue<PII, V<PII>, greater<PII>> pq;
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    PII p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) {
      continue;
    }
    for (auto &&[to, cost] : G[v]) {
      if (dis[to] > dis[v] + cost) {
        dis[to] = dis[v] + cost;
        prev[to] = v;
        pq.emplace(dis[to], to);
      }
    }
  }
  return prev;
}

/* get_path(prev, t)
  input: dijkstraで得たprev, ゴールt
  output: tへの最短路のパス
*/
VI get_path(const VI &prev, int t) {
  VI path;
  int now = t;
  while (now != -1) {
    path.push_back(now);
    now = prev[now];
  }
  reverse(ALL(path));
  return path;
}
