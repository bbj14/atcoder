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

// dp[i][w][k] : i番目まで、幅w以内、枚数k以内で重要度の合計の最大値
int dp[51][11001][55];

int main() {
  int w, n, K;
  cin >> w >> n >> K;

  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];

  rep(i, 0, n) rep(j, 0, w+1) rep(k, 0, K+1) {
    // i+1番目を選ばない場合
    chmax(dp[i + 1][j][k], dp[i][j][k]);
    // i+1番目を選ぶ場合
    chmax(dp[i + 1][j + a[i]][k + 1], dp[i][j][k] + b[i]);
  }

  cout << dp[n][w][K] << endl;
}
