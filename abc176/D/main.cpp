#pragma region Template  // clang-format off
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, m, n) for (int i = m; i < (int)(n); i++)
#define repe(i, m, n) for (int i = m; i <= (int)(n); i++)
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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
  int h, w, ch, cw, dh, dw;
  cin >> h >> w >> ch >> cw >> dh >> dw;
  ch--;
  cw--;
  dh--;
  dw--;

  vs S(h);
  rep(i, 0, h) { cin >> S[i]; }

  deque<vi> q;
  vvi cnt(h, vi(w, INT_MAX));
  // int n = 0;

  q.push_front({ch, cw, 0});

  while (q.size()) {
    auto now = q.front();
    q.pop_front();

    int d = now[2];

    rep(i, 0, 4) {
      int nh = now[0] + dx[i];
      int nw = now[1] + dy[i];

      if (nh < 0 || h <= nh || nw < 0 || w <= nw) continue;
      if (S[nh][nw] == '#') continue;
      if (cnt[nh][nw] <= d) continue;

      cnt[nh][nw] = d;

      q.push_front({nh, nw, d});
    }

    repe(i, -2, 2) repe(j, -2, 2) {
      // if (i == 0 && j == 0) continue;
      int nh = now[0] + i;
      int nw = now[1] + j;

      if (nh < 0 || h <= nh || nw < 0 || w <= nw) continue;
      if (S[nh][nw] == '#') continue;
      if (cnt[nh][nw] != INT_MAX) continue;

      cnt[nh][nw] = d + 1;

      q.push_back({nh, nw, d + 1});
    }
  }

  int ans = cnt[dh][dw];

  if (ans == INT_MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
