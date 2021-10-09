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

int main() {
  int n;
  cin >> n;
  vector<ll> x(n);
  rep(i, 0, n) cin >> x[i];

  ll ans1 = 0, ans2 = 0, ans3 = 0;
  rep(i, 0, n) {
    ans1 += abs(x[i]);
    ans2 += x[i] * x[i];
    chmax(ans3, abs(x[i]));
  }

  cout << ans1 << endl;
  printf("%.10lf\n", sqrt((double)ans2));
  cout << ans3 << endl;
}
