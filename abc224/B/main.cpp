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

const string YES = "Yes";
const string NO = "No";

int main() {
  int h, w;
  cin >> h >> w;

  vvi a(h, vi(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];

  bool ok = true;
  rep(i1, 0, h - 1) rep(i2, i1 + 1, h) rep(j1, 0, w - 1) rep(j2, j1 + 1, w) {
    if (!(a[i1][j1] + a[i2][j2] <= a[i2][j1] + a[i1][j2])) {
      ok = false;
      break;
    }
  }

  if (ok) yesno;
}
