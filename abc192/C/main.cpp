#pragma region Template  // clang-format off
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
#pragma endregion Template  // clang-format on

int main() {
  ll n, k;
  cin >> n >> k;

  rep(i, 0, k) {
    ll a = n;
    vector<int> v;
    while (a > 0) {
      v.push_back(a % 10);
      a /= 10;
    }
    sort(all(v));
    string g1, g2;
    if (a == 0) {
      g1 = "0";
      g2 = "0";
    }
    rep(j, 0, v.size()) {
      g1.push_back('0' + v[j]);
      g2.push_back('0' + v[v.size() - j - 1]);
    }
    n = stoll(g2) - stoll(g1);
  }
  cout << n << endl;
}
