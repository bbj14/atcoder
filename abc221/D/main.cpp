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
  vi a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];

  map<int, int> c;

  rep(i, 0, n) {
    c[a[i]]++;
    c[a[i] + b[i]]--;
  }

  int prev = 0;
  for (auto p : c) {
    c[p.first] += c[prev];

    prev = p.first;
  }

  map<int, int> ans;
  int prevf = 0;
  int prevs = 0;
  for (auto p : c) {
    ans[prevs] += p.first - prevf;
    prevf = p.first;
    prevs = p.second;
  }

  rep(i, 1, n + 1) {
    cout << ans[i];
    if (i < n) cout << " ";
  }
  cout << endl;
}
