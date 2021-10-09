#pragma region Template  // clang-format off
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
#pragma endregion Template  // clang-format on

int main() {
  vector<int> a(3, 0);
  rep(i, 0, 10) {
    char c;
    cin >> c;
    if (c == 'o') a[0]++;
    if (c == 'x') a[1]++;
    if (c == '?') a[2]++;
  }

  int ans;
  if (a[0] >= 5) ans = 0;
  if (a[0] == 4) ans = 24;
  if (a[0] == 3) ans = 36 + 24 * a[2];
  if (a[0] == 2) ans = 14 + 24 * a[2] + 12 * a[2] * a[2];
  if (a[0] == 1) ans = 1 + 4 * a[2] + 6 * a[2] * a[2] + 4 * a[2] * a[2] * a[2];
  if (a[0] == 0) ans = a[2] * a[2] * a[2] * a[2];

  cout << ans << endl;
}
