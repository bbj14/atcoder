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
  int n, p, q;
  cin >> n >> p >> q;

  vll a(n);
  rep(i, 0, n) cin >> a[i];

  int ans = 0;
  rep(i, 0, n) rep(j, 0, i) rep(k, 0, j) rep(l, 0, k) rep(m, 0, l) {
    ll s = a[i] * a[j] % p * a[k] % p * a[l] % p * a[m] % p;
    if (s == q) ans++;
  }
  cout << ans << endl;
}
