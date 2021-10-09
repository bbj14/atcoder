#pragma region Template  // clang-format off
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

const string YES = "Yes";
const string NO = "No";

int main() {
  int n;
  cin >> n;
  vvi d(n, vi(2));
  rep(i, 0, n) { cin >> d[i][0] >> d[i][1]; }

  bool ok = false;
  rep(i, 0, n - 2) {
    if (d[i][0] == d[i][1] && d[i + 1][0] == d[i + 1][1] &&
        d[i + 2][0] == d[i + 2][1])
      ok = true;
  }

  if (ok) yesno;
}
