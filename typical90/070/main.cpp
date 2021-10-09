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

int main() {
  int n;
  cin >> n;
  vi x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];

  ll sx = 0, sy = 0;

  rep(i, 0, n) {
    sx += x[i];
    sy += y[i];
  }

  sx = (sx + (n / 2)) / n;
  sy = (sy + (n / 2)) / n;

  ll ans = 0;
  rep(i, 0, n) { ans += abs(sx - x[i]) + abs(sy - y[i]); }
  cout << ans << endl;
}