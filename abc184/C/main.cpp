// clang-format off
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, m, n) for (int i = m; i < (int)(n); i++)
#define repe(i, m, n) for (int i = m; i <= (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define yesno {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
using ll = long long;
using vvi = vector<vector<int>>;
using P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// clang-format on

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll x = abs((a + b) - (c + d));
  ll y = abs((a - b) - (c - d));
  ll z = abs(a - c) + abs(b - d);

  int ans;
  if (a == c && b == d) {
    ans = 0;
  } else if (x == 0 || y == 0 || z <= 3) {
    ans = 1;
  } else if ((a + b) % 2 == (c + d) % 2 || x <= 3 || y <= 3 || z <= 6) {
    ans = 2;
  } else {
    ans = 3;
  }

  cout << ans << endl;
}
