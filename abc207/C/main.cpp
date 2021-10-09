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

  vector<double> l(n), r(n);
  rep(i, 0, n) {
    int t;
    double ll, rr;
    cin >> t >> ll >> rr;
    ll -= 1, rr -= 1;
    if (t == 2) rr -= 0.1;
    if (t == 3) ll += 0.1;
    if (t == 4) {
      ll += 0.1;
      rr -= 0.1;
    }
    l[i] = ll, r[i] = rr;
  }

  int ans = 0;
  rep(i, 0, n - 1) rep(j, i + 1, n) {
    if (l[i] <= l[j] && l[j] <= r[i])
      ans++;
    else if (l[j] <= l[i] && l[i] <= r[j])
      ans++;
  }

  cout << ans << endl;
}
