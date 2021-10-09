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
  int r, c, sy, sx, gy, gx;
  cin >> r >> c >> sy >> sx >> gy >> gx;
  sx--;
  sy--;
  gy--;
  gx--;

  vector<string> a(r);
  rep(i, 0, r) { cin >> a[i]; }

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  queue<vector<int>> Q;
  Q.push({sy, sx, 0});

  vvi seen(r, vector<int>(c));

  while (Q.size() > 0) {
    auto now = Q.front();
    Q.pop();

    if (now[0] == gy && now[1] == gx) {
      cout << now[2] << endl;
      return 0;
    }

    rep(i, 0, 4) {
      auto next = now;
      next[0] = now[0] + dx[i];
      next[1] = now[1] + dy[i];
      next[2] += 1;

      if (seen[next[0]][next[1]] || a[next[0]][next[1]] == '#') continue;
      Q.push(next);
      seen[next[0]][next[1]] = true;
    }
  }
}
