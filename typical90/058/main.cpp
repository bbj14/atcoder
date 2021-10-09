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

const long long MOD = 100000;

int main() {
  ll n, k;
  cin >> n >> k;

  map<int, int> mp;
  rep(i, 0, MOD) {
    int x = i, y = i;
    while (y) {
      x += y % 10;
      y /= 10;
    }
    mp[i] = x % MOD;
  }

  vi seen(MOD, -1);
  int now = n, cnt = 0, f, lp, ans;
  seen[now] = 0;

  while (true) {
    now = mp[now];
    if (seen[now] >= 0) {
      ans = now;
      f = seen[now];
      lp = cnt + 1 - seen[now];
      break;
    }
    seen[now] = ++cnt;
  }

  if (lp != 0 && k > f)
    k = (k - f) % lp;
  else
    ans = n;

  rep(i, 0, k) ans = mp[ans];
  cout << ans << endl;
}
