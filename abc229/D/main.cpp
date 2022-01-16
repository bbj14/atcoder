#pragma region Template  // clang-format off
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#define REP(i,n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,n) for (int i = n-1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
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
  string s;
  CIN(s);
  int k;
  CIN(k);
  int le = 0;
  int cnt = 0, ans = 0;
  VI dot;
  REP(i, s.size()) {
    if (s[i] == '.') dot.push_back(i);
  }
  reverse(ALL(dot));

  REP(i, s.size()) {
    if (s[i] == '.') {
      if (k == 0) {
        le = dot.back() + 1;
        dot.pop_back();
      } else {
        k--;
      }
    }
    chmax(ans, i - le + 1);
  }
  COUT(ans);
}
