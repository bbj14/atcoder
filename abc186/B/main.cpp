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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// clang-format on

int main() {
  int h, w;
  cin >> h >> w;

  vvi A(h);
  int min = 100;
  rep(i, 0, h) {
    rep(j, 0, w) {
      int a;
      cin >> a;
      chmin(min, a);
      A[i].push_back(a);
    }
  }

  int ans = 0;
  rep(i, 0, h) {
    rep(j, 0, w) { ans += A[i][j] - min; }
  }
  cout << ans << endl;
}
