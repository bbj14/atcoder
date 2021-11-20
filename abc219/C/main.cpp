#pragma region Template  // clang-format off
#include <bits/stdc++.h>

#include <atcoder/all>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
#define REP(i,n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,n) for (int i = n; i > 0; i--)
#define FOR(i, m, n) for (int i = m; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define YESNO {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define int ll
using ll = long long;
using ull = unsigned long long;
using bint = boost::multiprecision::cpp_int;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
using VI = V<int>;
using VVI = VV<int>;
using VS = V<string>;
using VB = V<bool>;
using PII = pair<int,int>;
using MII = map<int,int>;
void CIN() {}; template <class T, class... U> void CIN(T &&x, U &&...y) {cin >> x; CIN(forward<U>(y)...);}
void _COUT() { cout << '\n'; } template <class T, class... U> void _COUT(T &&x, U &&...y) {cout << ' ' << x; _COUT(forward<U>(y)...);}
void COUT() { _COUT(); }; template <class T, class... U> void COUT(T &&x, U &&...y) {cout << x; _COUT(forward<U>(y)...);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#pragma endregion Template  // clang-format on

signed main() {
  string x;
  CIN(x);

  map<char, int> mp;
  REP(i, x.length()) { mp[x[i]] = i; }

  int n;
  CIN(n);

  VS s(n);
  REP(i, n) CIN(s[i]);

  sort(ALL(s), [&](string a, string b) {
    REP(i, min(a.length(), b.length())) {
      if (a[i] != b[i]) {
        return mp[a[i]] < mp[b[i]];
      }
    }
    return a.length() < b.length();
  });

  for (auto ss : s) COUT(ss);
}
