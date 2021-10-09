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

// dp[a][b][c]
// 技術力a、語学力b、コミュニケーション力cで応募可能な中で最も年収が高い会社の年収
int dp[105][105][105];

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, 0, n) {
    int a, b, c, w;
    cin >> a >> b >> c >> w;

    chmax(dp[a][b][c], w);
  }

  rep(i, 0, 101) rep(j, 0, 101) rep(k, 0, 101) {
    chmax(dp[i + 1][j][k], dp[i][j][k]);
    chmax(dp[i][j + 1][k], dp[i][j][k]);
    chmax(dp[i][j][k + 1], dp[i][j][k]);
  }

  rep(i, 0, m) {
    int x, y, z;
    cin >> x >> y >> z;

    cout << dp[x][y][z] << endl;
  }
}
