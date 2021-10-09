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

const int dh[] = {1, -1, 0, 0};
const int dw[] = {0, 0, 1, -1};

int cnt[1001][1001][4];

int main() {
  int h, w, rs, cs, rt, ct;
  cin >> h >> w >> rs >> cs >> rt >> ct;
  rs--;
  cs--;
  rt--;
  ct--;

  vs s(h);
  rep(i, 0, h) cin >> s[i];

  deque<vi> D;
  D.push_front({rs, cs, -1});

  while (D.size() > 0) {
    vi now = D.front();
    D.pop_front();

    int h1 = now[0], w1 = now[1], to = now[2];

    if (h1 == rt && w1 == ct) {
      cout << cnt[h1][w1][to] << endl;
      return 0;
    }

    rep(i, 0, 4) {
      int h2 = now[0] + dh[i];
      int w2 = now[1] + dw[i];
      if (h2 < 0 || h <= h2 || w2 < 0 || w <= w2) continue;
      if (s[h2][w2] == '#') continue;
      if (h2 == rs && w2 == cs) continue;
      if (cnt[h2][w2][i] && (cnt[h2][w2][i] <= cnt[h1][w1][to])) continue;

      // 直進の場合は先頭に追加・曲がる場合は末尾に追加
      if (to == -1 || i == to) {
        cnt[h2][w2][i] = cnt[h1][w1][to];
        D.push_front({h2, w2, i});
      } else {
        cnt[h2][w2][i] = cnt[h1][w1][to] + 1;
        D.push_back({h2, w2, i});
      }
    }
  }
}
