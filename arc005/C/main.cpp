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

const string YES = "YES";
const string NO = "NO";

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> a(h);
  rep(i, 0, h) cin >> a[i];

  deque<vector<int>> Q;
  vvi seen(h, vector<int>(w));

  // スタートを探す
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (a[i][j] == 's') {
        // 3個目は壊した塀の数
        Q.push_front({i, j, 0});
        seen[i][j] = 1;
      }
    }
  }

  while (Q.size() > 0) {
    // 先頭を取り出す
    auto now = Q.front();
    Q.pop_front();

    rep(i, 0, 4) {
      auto next = now;
      next[0] = now[0] + dx[i];
      next[1] = now[1] + dy[i];

      // 範囲外の場合
      if (next[0] < 0 || h <= next[0] || next[1] < 0 || w <= next[1]) continue;

      // ゴールに着いた場合
      if (a[next[0]][next[1]] == 'g') {
        cout << YES << endl;
        return 0;
      }

      // すでに探索した場合
      if (seen[next[0]][next[1]]) continue;
      seen[next[0]][next[1]] = true;

      if (a[next[0]][next[1]] == '#') {
        // すでに2回塀を壊していたらそれ以上は進めない
        if (now[2] == 2) continue;

        next[2] += 1;
        // 塀の場合は末尾に追加
        Q.push_back(next);
      } else {
        // 道の場合は先頭に追加
        Q.push_front(next);
      }
    }
  }

  cout << NO << endl;
}
