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

const string YES = "Yes";
const string NO = "No";

int main() {
  int n, m;
  cin >> n >> m;

  vvi b(n, vi(m));
  rep(i, 0, n) rep(j, 0, m) cin >> b[i][j];

  // int rem = b[0][0] % 7;
  // if (rem == 0) rem = 7;
  // if (rem + m > 8) {
  //   cout << NO << endl;
  //   return 0;
  // }

  ll prev = 0;

  rep(i, 0, n) {
    ll now = b[i][0];
    if (i > 0) {
      if (now != prev + 7) {
        cout << NO << endl;
        return 0;
      }
    }
    prev = now;

    rep(j, 1, m) {
      if (b[i][j] != b[i][j - 1] + 1) {
        cout << NO << endl;
        return 0;
      }
    }
  }
  cout << YES << endl;
}
