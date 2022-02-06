#pragma region Template  // clang-format off
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#define REP(i,n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,n) for (int i = n-1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define YESNO {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define int ll
using ll = long long;
using ull = unsigned long long;
using bint = boost::multiprecision::cpp_int;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
using VI = V<int>;
using VVI = VV<int>;
using VS = V<string>;
using VB = V<bool>;
using PII = pair<int,int>;
using MII = map<int,int>;
void CIN() {}; template <class T, class... U> void CIN(T &&x, U &&...y) {cin >> x; CIN(forward<U>(y)...);}
void _COUT() { cout << '\n'; } template <class T, class... U> void _COUT(T &&x, U &&...y) {cout << ' ' << x; _COUT(forward<U>(y)...);}
void COUT() { _COUT(); }; template <class T, class... U> void COUT(T &&x, U &&...y) {cout << x; _COUT(forward<U>(y)...);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#pragma endregion Template  // clang-format on

const int INF = LONG_LONG_MAX - 1;

int dist[15][15];

signed main() {
  int n, k;
  CIN(n, k);
  VI x(n), y(n);
  REP(i, n) CIN(x[i], y[i]);

  VI d(1 << n);
  VVI dp(k + 1, VI(1 << n, INF));

  REP(i, n) REP(j, n) {
    dist[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
  }

  REP(i, 1 << n) REP(j, n) REP(m, j) {
    if (i & (1 << j) && i & (1 << m)) chmax(d[i], dist[j][m]);
  }

  dp[0][0] = 0;

  FOR(i, 1, k + 1) REP(j, 1 << n) {
    for (int b = j;; b = (b - 1) & j) {
      chmin(dp[i][j], max(dp[i - 1][b], d[j - b]));
      if (b == 0) break;
    }
  }

  COUT(dp[k][(1 << n) - 1]);
}
