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
  ll k;
  cin >> k;

  vll a;
  a.push_back(1);
  for (ll i = 2; i * i <= k; i++) {
    if (k % i == 0) {
      a.push_back(i);
      a.push_back(k / i);
    }
  }
  sort(all(a));

  ll ans = 0;
  rep(i, 0, a.size()) rep(j, i, a.size()) {
    if ((k % a[i] == 0) && (k / a[i] % a[j] == 0) &&
        (k / a[i] / a[j] >= a[j])) {
      ans++;
    }
  }
  cout << ans << endl;
}
