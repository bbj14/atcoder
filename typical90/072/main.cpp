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

int used[20][20];
int ma;

int dh[] = {0, 1, 0, -1};
int dw[] = {1, 0, -1, 0};

vs c;
int H, W, sh, sw;

void dfs(int h, int w, int cnt) {
  used[h][w] = 1;
  rep(i, 0, 4) {
    int nh = h + dh[i];
    int nw = w + dw[i];

    if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
    if (c[nh][nw] == '#') continue;
    if (cnt > 2 && nh == sh & nw == sw) {
      chmax(ma, cnt);
      continue;
    }
    if (used[nh][nw]) continue;

    dfs(nh, nw, cnt + 1);
  }
  used[h][w] = 0;
}

int main() {
  cin >> H >> W;

  c = vs(H);
  rep(i, 0, H) cin >> c[i];

  int ans = -1;
  rep(i, 0, H) rep(j, 0, W) {
    if (c[i][j] == '#') continue;

    ma = -1;
    sh = i, sw = j;
    dfs(i, j, 1);
    chmax(ans, ma);
  }
  cout << ans << endl;
}
