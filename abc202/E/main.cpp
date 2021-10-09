#pragma region Template  // clang-format off
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, m, n) for (int i = m; i < (int)(n); i++)
#define repe(i, m, n) for (int i = m; i <= (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define yesno {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#pragma endregion Template  // clang-format on

vvi children, res;
vi in, out, dep;

int t;

void dfs(int v, int d) {
  in[v] = t;
  dep[v] = d;
  res[d].push_back(t);
  t++;
  for (int c : children[v]) {
    dfs(c, d + 1);
  }
  out[v] = t;
}

int main() {
  int n;
  cin >> n;
  children = res = vvi(n);
  in = out = dep = vi(n);

  repe(i, 2, n) {
    int p;
    cin >> p;
    children[p - 1].push_back(i - 1);
  }
  dfs(0, 0);

  int q;
  cin >> q;
  rep(i, 0, q) {
    int u, d;
    cin >> u >> d;

    int ans = lower_bound(all(res[d]), out[u - 1]) -
              lower_bound(all(res[d]), in[u - 1]);
    cout << ans << endl;
  }
}
