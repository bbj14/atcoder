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
  ll n, k;
  cin >> n >> k;
  ll x = k / n;
  k %= n;
  vvll a(n, vll(3));
  rep(i, 0, n) {
    a[i][0] = i;
    cin >> a[i][1];
    a[i][2] = x;
  }

  sort(all(a), [](vll a, vll b) { return a[1] < b[1]; });

  rep(i, 0, k) a[i][2]++;

  sort(all(a));

  rep(i, 0, n) cout << a[i][2] << endl;
}
