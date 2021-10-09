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
  string n;
  cin >> n;

  int ans = 0;
  rep(i, 1, (1 << n.length()) - 1) {
    string a, b;
    rep(j, 0, n.length()) {
      if (i & (1 << j)) {
        a.push_back(n[j]);
      } else {
        b.push_back(n[j]);
      }
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    if (a == "") continue;
    if (b == "") continue;

    int x = stoi(a);
    int y = stoi(b);

    if (x == 0) continue;
    if (y == 0) continue;

    chmax(ans, x * y);
  }
  cout << ans << endl;
}
