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
  int n, q;
  cin >> n >> q;

  vi a(n);
  rep(i, 0, n) cin >> a[i];

  vll d(n - 1);
  rep(i, 0, n - 1) d[i] = a[i + 1] - a[i];

  ll x = 0;
  rep(i, 0, n - 1) x += abs(d[i]);

  rep(i, 0, q) {
    int l, r, v;
    cin >> l >> r >> v;

    ll ldif = 0, rdif = 0;

    if (l >= 2) {
      ldif = -abs(d[l - 2]);
      d[l - 2] += v;
      ldif += abs(d[l - 2]);
    }
    if (r <= n - 1) {
      rdif = -abs(d[r - 1]);
      d[r - 1] -= v;
      rdif += abs(d[r - 1]);
    }

    x += ldif + rdif;
    cout << x << endl;
  }
}
