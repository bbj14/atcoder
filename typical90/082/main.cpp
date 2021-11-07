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

const long long MOD = 1000000007;
using mint = modint1000000007;

int main() {
  ll l, r;
  cin >> l >> r;

  ll now = 1;
  mint ans = 0;
  ll cnt = 1;
  bool last = false;

  while (true) {
    if (now == 1000000000000000000) {
      mint rem = now;
      rem *= 19;
      ans += rem;
      cout << ans.val() << endl;
      return 0;
    }
    ll le = now;
    ll ri = le * 10 - 1;
    if (le * 10 <= l) {
      cnt++;
      now *= 10;
      continue;
    }
    if (le < l) le = l;
    if (ri >= r) {
      ri = r;
      last = true;
    }

    ans += mint(le + ri) * (ri - le + 1) / 2 * cnt;

    if (last) {
      cout << ans.val() << endl;
      return 0;
    }

    now *= 10;
    cnt++;
  }
}