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

const long long MOD = 998244353;

int main() {
  ll n, m;
  cin >> n >> m;

  dsu d(n);
  vi e(n);

  rep(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    e[u]++;

    d.merge(u, v);
  }

  vi cntV(n), cntE(n);

  rep(i, 0, n) {
    cntV[d.leader(i)]++;
    cntE[d.leader(i)] += e[i];
  }

  ll cnt = 0;
  rep(i, 0, n) {
    if (cntV[i] == 0) continue;
    if (cntV[i] != cntE[i]) {
      cout << 0 << endl;
      return 0;
    }
    cnt++;
  }

  cout << "test" << endl;

  cout << pow_mod(2LL, cnt, MOD) << endl;
}
