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
  vector<pair<int, vi>> v;

  int c = k * k / 2 + 1;

  rep(i, 0, n) rep(j, 0, n) {
    int a;
    cin >> a;
    v.push_back({a, {i, j}});
  }

  sort(all(v));

  rep(i, 0, n) {
    int min_i = 0, min_j = 0, max_i = n, max_j = n;
    rep(j, 0, i + k * k) {
      chmax(min_i, v[j].second[0]);
      chmax(min_j, v[j].second[1]);
      chmin(max_i, v[j].second[0]);
      chmin(max_j, v[j].second[1]);
    }
    if (max_i - min_i < k && max_j - min_j < k) {
      cout << v[i + k * k - c].first << endl;
      return 0;
    }
  }
}
