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

int dp[100005][10];

int main() {
  int n;
  cin >> n;
  vi a(n);
  rep(i, 0, n) cin >> a[i];

  dp[0][a[0]] = 1;

  rep(i, 0, n - 1) rep(j, 0, 10) {
    int f = (j + a[i + 1]) % 10;
    int g = (j * a[i + 1]) % 10;
    dp[i + 1][f] += dp[i][j];
    dp[i + 1][f] %= MOD;
    dp[i + 1][g] += dp[i][j];
    dp[i + 1][g] %= MOD;
  }

  rep(i, 0, 10) { cout << dp[n - 1][i] << endl; }
}
