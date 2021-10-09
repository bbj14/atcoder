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
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> t(n, vector<ll>(n));
  rep(i, 0, n) rep(j, 0, n) cin >> t[i][j];

  vector<int> a(n - 1);
  iota(all(a), 1);

  int ans = 0;
  do {
    ll sum = 0;
    sum += t[0][a[0]];
    rep(i, 1, n - 1) { sum += t[a[i - 1]][a[i]]; }
    sum += t[a[n - 2]][0];
    if (sum == k) ans++;
  } while (next_permutation(all(a)));

  cout << ans << endl;
}
