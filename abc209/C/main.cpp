#pragma region Template  // clang-format off
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

const long long MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vi c(n);
  rep(i, 0, n) cin >> c[i];

  sort(all(c));

  ll ans = 1;
  rep(i, 0, n) {
    ll now = c[i] - i;
    chmax(now, ll(0));
    ans = ans * now % MOD;
  }

  cout << ans << endl;
}
