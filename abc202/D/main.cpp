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

ll c[61][61];

int main() {
  ll a, b, k;
  cin >> a >> b >> k;

  c[0][0] = 1;
  repe(i, 1, 60) {
    repe(j, 0, i) { c[i][j] = c[i - 1][j - 1] + c[i - 1][j]; }
  }

  while (a + b > 0) {
    if (k <= c[a + b - 1][a - 1]) {
      cout << 'a';
      a--;
    } else {
      cout << 'b';
      k -= c[a + b - 1][a - 1];
      b--;
    }
  }
  cout << endl;
}
