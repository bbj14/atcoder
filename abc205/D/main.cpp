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
  int n, q;
  cin >> n >> q;

  vll a(n);
  rep(i, 0, n) cin >> a[i];

  vll c;
  c.push_back(a[0] - 1);
  rep(i, 1, n) { c.push_back(c[i - 1] + a[i] - a[i - 1] - 1); }

  rep(i, 0, q) {
    ll k;
    cin >> k;

    int x = lower_bound(all(c), k) - c.begin();

    if (x == 0)
      cout << k << endl;
    else {
      cout << a[x - 1] + k - c[x - 1] << endl;
    }
  }
}
