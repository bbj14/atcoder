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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, 0, m) cin >> a[i];

  sort(all(a));

  if (a.size() == 0) {
    cout << 1 << endl;
    return 0;
  }

  vi d;
  d.push_back(a[0] - 1);
  rep(i, 1, m) { d.push_back(a[i] - a[i - 1] - 1); }
  d.push_back(n - a.back());
  d.erase(remove(all(d), 0), d.end());
  
  if (d.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  
  sort(all(d));
  int mi = d.front();
  ll ans = 0;
  
  for (int i : d) {
    ans += (i + mi -1) / mi;
  }
  cout << ans << endl;
}
