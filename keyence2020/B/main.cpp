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
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#pragma endregion Template  // clang-format on

int main() {
  int n;
  cin >> n;
  vector<pii> R(n);
  for (auto &[r, l] : R) {
    int a, b;
    cin >> a >> b;
    r = a + b;
    l = a - b;
  }
  sort(all(R));

  int ans = 1, now_r = R[0].first;
  rep(i, 1, n) {
    if (now_r <= R[i].second) {
      ans++;
      now_r = R[i].first;
    }
  }

  cout << ans << endl;
}
