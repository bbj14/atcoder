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
using vvi = vector<vector<int>>;
using vs = vector<string>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#pragma endregion Template  // clang-format on

const long long MOD = 1000000007;
using mint = modint1000000007;

int main() {
  int n;
  cin >> n;
  vector<mint> a(n), s(n);
  rep(i, 0, n) cin >> a[i];
  s[0] = a[0];
  rep(i, 0, n - 1) s[i + 1] = a[i + 1] + s[i];

  mint sum = 0;
  for (int i = n - 1; i > 0; i--) {
    sum += a[i] * s[i - 1];
  }
  cout << sum.val() << endl;
}
