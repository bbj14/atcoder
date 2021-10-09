#pragma region Template  // clang-format off
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, m, n) for (int i = m; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define yesno {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#pragma endregion Template  // clang-format on

int n, q;
vi color;
vvi G;

void dfs(int v) {
  for (auto ne : G[v]) {
    if (color[ne] >= 0) continue;
    color[ne] = 1 - color[v];
    dfs(ne);
  }
}

int main() {
  cin >> n >> q;
  color = vi(n, -1);
  G = vvi(n);
  rep(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(0);

  rep(i, 0, q) {
    int c, d;
    cin >> c >> d;
    c--, d--;

    if (color[c] != color[d]) {
      cout << "Road" << endl;
    } else {
      cout << "Town" << endl;
    }
  }
}
