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

const int dh[] = {1, -1, 0, 0};
const int dw[] = {0, 0, 1, -1};

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> a(h);
  rep(i, 0, h) cin >> a[i];

  queue<vector<int>> Q;

  rep(i, 0, h) rep(j, 0, w) {
    if (a[i][j] == '#') Q.push({i, j});
  }

  int ans = -1;
  while (Q.size() > 0) {
    vvi black;
    while (Q.size() > 0) {
      black.push_back(Q.front());
      Q.pop();
    }

    for (auto now : black) {
      rep(i, 0, 4) {
        auto next = now;
        next[0] += dh[i];
        next[1] += dw[i];

        if (next[0] < 0 || next[0] >= h || next[1] < 0 || next[1] >= w)
          continue;

        if (a[next[0]][next[1]] == '#') continue;

        a[next[0]][next[1]] = '#';
        Q.push(next);
      }
    }
    ans++;
  }
  cout << ans << endl;
}
