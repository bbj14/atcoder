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
  vi a(n);
  rep(i, 0, n) cin >> a[i];

  map<int, int> mp;
  rep(i, 0, n) mp[a[i]]++;

  vi b;
  for (auto m : mp) b.push_back(m.second);
  reverse(all(b));

  ll ans = 1;
  rep(i, 0, b.size()) {
    while (b[i]) {
      if (b[i] == 1) {
        if (i == b.size() - 1) {
          ans *= 1;
        } else {
          ans *= b[i + 1] + 1;
        }
      } else {
        ans *= b[i];
      }
      b[i]--;
    }
  }

  cout << ans << endl;
}