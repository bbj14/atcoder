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

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  rep(i, 0, n) cin >> c[i];

  map<int, int> m;
  int cnt = 0, ans = 0;
  rep(i, 0, n) {
    if (m[c[i]] == 0) cnt++;
    m[c[i]]++;
    if (i >= k) {
      m[c[i - k]]--;
      if (m[c[i - k]] == 0) cnt--;
    }
    chmax(ans, cnt);
  }
  cout << ans << endl;
}
