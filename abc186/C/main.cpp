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
  int n;
  cin >> n;

  int ans = 0;
  repe(i, 1, n) {
    bool ok = true;
    int num = i;
    while (num > 0) {
      if (num % 10 == 7) {
        ok = false;
        break;
      }
      num /= 10;
    }
    num = i;
    while (num > 0) {
      if (num % 8 == 7) {
        ok = false;
        break;
      }
      num /= 8;
    }
    if (ok) ans++;
  }

  cout << ans << endl;
}
