#pragma region Template  // clang-format off
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, m, n) for (int i = m; i < (int)(n); i++)
#define repe(i, m, n) for (int i = m; i <= (int)(n); i++)
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

vi seen;
ll ans;

void dfs(vvi &G, int i) {
  seen[i] = 1;
  ans++;
  for (int ne : G[i]) {
    if (seen[ne]) continue;
    dfs(G, ne);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vvi G(n);

  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
  }

  rep(i, 0, n) {
    seen = vi(n, 0);
    dfs(G, i);
  }

  cout << ans << endl;
}
