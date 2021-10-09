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
  int k;
  cin >> k;

  string T, A;
  cin >> T >> A;

  vector<ll> c(10, k), t(10), a(10);
  rep(i, 0, 4) {
    t[T[i] - '0']++;
    a[A[i] - '0']++;
    c[T[i] - '0']--;
    c[A[i] - '0']--;
  }

  ll twin = 0, awin = 0;
  repe(i, 1, 9) repe(j, 1, 9) {
    auto tt = t, aa = a;
    tt[i]++;
    aa[j]++;
    ll tsum = 0, asum = 0, n = 0;
    if (i == j) {
      n = c[i] * (c[i] - 1);
    } else {
      n = c[i] * c[j];
    }
    repe(k, 1, 9) {
      tsum += k * (ll)pow(10, tt[k]);
      asum += k * (ll)pow(10, aa[k]);
    }
    if (tsum > asum)
      twin += n;
    else
      awin += n;
  }

  double ans = (double)twin / (twin + awin);
  printf("%.10f\n", ans);
}
