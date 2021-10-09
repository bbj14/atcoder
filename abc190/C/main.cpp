#pragma region Template  // clang-format off
#define _GLIBCXX_DEBUG
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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, 0, m) cin >> a[i] >> b[i];

  int k;
  cin >> k;

  vector<int> c(k), d(k);
  rep(i, 0, k) cin >> c[i] >> d[i];

  int ans = 0;
  for (int i = 0; i < (1 << k); i++) {
    vi s(n);
    rep(j, 0, k) {
      if (i & (1 << j))
        s[c[j] - 1]++;
      else
        s[d[j] - 1]++;
    }

    int cnt = 0;
    rep(j, 0, m) {
      if (s[a[j] - 1] && s[b[j] - 1]) cnt++;
    }
    chmax(ans, cnt);
  }
  cout << ans << endl;
}
