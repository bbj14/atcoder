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

int f(char a, char b) {
  if (a == 'G') {
    if (b == 'G') return 0;
    if (b == 'C') return 1;
    if (b == 'P') return 2;
  }
  if (a == 'C') {
    if (b == 'G') return 2;
    if (b == 'C') return 0;
    if (b == 'P') return 1;
  }
  if (a == 'P') {
    if (b == 'G') return 1;
    if (b == 'C') return 2;
    if (b == 'P') return 0;
  }
  return 0;
}

bool comp(pii p1, pii p2) {
  if (p1.first != p2.first) {
    return p1.first > p2.first;
  }
  return p1.second < p2.second;
}

int main() {
  int n, m;
  cin >> n >> m;
  n *= 2;

  vs a(n);
  rep(i, 0, n) cin >> a[i];

  vector<pii> w(n);
  rep(i, 0, n) {
    w[i].first = 0;
    w[i].second = i;
  }

  rep(i, 0, m) {
    rep(j, 0, n / 2) {
      int p1 = w[2 * j].second;
      int p2 = w[2 * j + 1].second;
      int result = f(a[p1][i], a[p2][i]);

      if (result == 1) w[2 * j].first++;
      if (result == 2) w[2 * j + 1].first++;
    }

    sort(all(w), comp);
  }

  rep(i, 0, n) { cout << w[i].second + 1 << endl; }
}
