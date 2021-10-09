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

int main() {
  int h, w, K;
  cin >> h >> w >> K;

  vs c(h);

  rep(i, 0, h) cin >> c[i];

  int black = 0;
  rep(i, 0, h) rep(j, 0, w) if (c[i][j] == '#') black++;

  int ans = 0;
  rep(i, 0, 1 << h) rep(j, 0, 1 << w) {
    int cnt = black;
    rep(k, 0, h) rep(l, 0, w) {
      if ((i & 1 << k) || (j & 1 << l)) {
        if (c[k][l] == '#') cnt--;
      }
    }
    if (cnt == K) ans++;
  }
  cout << ans << endl;
}
