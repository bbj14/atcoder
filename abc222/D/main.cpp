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

const long long MOD = 998244353;

using mint = modint998244353;

mint dp[3005][3005];

int main() {
  int n;
  cin >> n;
  vi a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];

  rep(i, a[0], b[0] + 1) { dp[0][i] = 1; }

  rep(i, 0, n - 1) {
    mint cnt = 0;
    rep(j, 0, 3001) {
      cnt += dp[i][j];
      if (a[i + 1] <= j && j <= b[i + 1]) dp[i + 1][j] = cnt;
    }
  }

  mint ans = 0;
  rep(i, a[n - 1], b[n - 1] + 1) ans += dp[n - 1][i];
  cout << ans.val() << endl;
}
