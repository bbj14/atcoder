#pragma region Template  // clang-format off
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#define REP(i,n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,n) for (int i = n-1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define YESNO {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define int ll
using ll = long long;
using ull = unsigned long long;
using bint = boost::multiprecision::cpp_int;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
using VI = V<int>;
using VVI = VV<int>;
using VS = V<string>;
using VB = V<bool>;
using PII = pair<int,int>;
using MII = map<int,int>;
void CIN() {}; template <class T, class... U> void CIN(T &&x, U &&...y) {cin >> x; CIN(forward<U>(y)...);}
void _COUT() { cout << '\n'; } template <class T, class... U> void _COUT(T &&x, U &&...y) {cout << ' ' << x; _COUT(forward<U>(y)...);}
void COUT() { _COUT(); }; template <class T, class... U> void COUT(T &&x, U &&...y) {cout << x; _COUT(forward<U>(y)...);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#pragma endregion Template  // clang-format on

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

signed main() {
  int n, m;
  CIN(n, m);
  VV<PII> G(n);
  REP(i, m) {
    int a, b, c;
    CIN(a, b, c);
    a--, b--;
    G[a].emplace_back(b, c);
    G[b].emplace_back(a, c);
  }

  VI dis1, disn;
  dijkstra(G, 0, dis1);
  dijkstra(G, n - 1, disn);

  REP(i, n) COUT(dis1[i] + disn[i]);
}
