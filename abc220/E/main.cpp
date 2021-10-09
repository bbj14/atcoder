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

int main() {
  int n, d;
  cin >> n >> d;

  ll ans = 0;
  rep(i, 0, n) {
    ll vs = pow_mod(2, i, MOD);
    ll sum = 0;
    // 下に行く
    if (i != n - 1) {
      if ((n - i - 1) >= d) {
        sum += pow_mod(2, d, MOD);
      }
    }

    // 上に行く
    if (i != 0) {
      // 根までいかない
      if (d <= i) {
        sum += pow_mod(2, d - 1, MOD);
      } else {
        sum += pow_mod(2, d - 2, MOD);
      }
    }
    ans += vs * sum;
    ans %= MOD;
  }
  cout << ans << endl;
}
