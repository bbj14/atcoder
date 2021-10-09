// clang-format off
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
// clang-format on

int main() {
  ll n, m, t;
  cin >> n >> m >> t;

  ll rem = n;
  ll time = 0;
  rep(i, 0, m) {
    ll a, b;
    cin >> a >> b;
    rem -= a - time;
    if (rem <= 0) {
      puts("No");
      return 0;
    }
    rem += b - a;
    chmin(rem, n);

    if (i == m - 1) {
      rem -= t - b;
      if (rem <= 0) {
        puts("No");
        return 0;
      }
    }
    time = b;
  }

  puts("Yes");
}
