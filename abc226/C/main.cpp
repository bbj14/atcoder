#pragma region Template  // clang-format off
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using bint = boost::multiprecision::cpp_int;
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

map<int, bool> used;

void dfs(vvi &G, int v) {
  used[v] = true;
  for (auto nv : G[v]) {
    if (used[nv]) continue;
    dfs(G, nv);
  }
}

int main() {
  int n;
  cin >> n;
  vi t(n), k(n);
  vvi a(n);

  rep(i, 0, n) {
    cin >> t[i] >> k[i];
    rep(j, 0, k[i]) {
      int x;
      cin >> x;
      x--;
      a[i].push_back(x);
    }
  }

  dfs(a, n - 1);

  ll ans = 0;
  for (auto [i, v] : used) {
    ans += t[i];
  }
  cout << ans << endl;
}
