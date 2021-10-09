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
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> m;
  rep(i, 0, n) {
    int x;
    cin >> x;
    a[i] = x;
    m[x] = x;
  }

  vi b(n / 2), c(n / 2);
  rep(i, 0, n / 2) {
    b[i] = a[i];
    c[i] = a[n - i - 1];
  }

  int ans = 0;
  map<int, int> ma;
  rep(i, 0, n / 2) {
    if (m[b[i]] != m[c[i]]) {
      ans++;
      ma[m[c[i]]] = m[b[i]];

      int x = ma[m[b[i]]];
      if (x) m[x] = m[c[i]];

      m[b[i]] = m[c[i]];
    }
  }
  cout << ans << endl;
}
