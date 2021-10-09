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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);

  rep(i, 0, h) { cin >> s[i]; }

  int ans = 0;
  rep(i, 0, h - 1) rep(j, 0, w - 1) {
    int cnt = 0;
    if (s[i][j] == '#') cnt++;
    if (s[i + 1][j] == '#') cnt++;
    if (s[i][j + 1] == '#') cnt++;
    if (s[i + 1][j + 1] == '#') cnt++;

    if (cnt == 1 || cnt == 3) ans++;
  }

  cout << ans << endl;
}
