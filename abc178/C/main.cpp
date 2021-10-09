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

const long long MOD = 1000000007;

ll dp[1001001][3];

int main() {
  ll n;
  cin >> n;

  dp[1][0] = 0;
  dp[1][1] = 2;
  dp[1][2] = 8;

  repe(i, 2, n) {
    dp[i][0] = (dp[i - 1][0] * 10 + dp[i - 1][1]) % MOD;
    dp[i][1] = (dp[i - 1][1] * 9 + dp[i - 1][2] * 2) % MOD;
    dp[i][2] = (dp[i - 1][2] * 8) % MOD;
  }

  cout << dp[n][0] << endl;
}
