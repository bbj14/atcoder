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

int main() {
  bint n;
  int k;
  cin >> n >> k;

  rep(i, 0, k) {
    ll ten = 0, x = 1;
    while (n) {
      ten += (int)(n % 10) * x;
      n /= 10;
      x *= 8;
    }

    n = 0, x = 1;
    while (ten) {
      ll y = ten % 9;
      if (y == 8) y = 5;
      n += y * x;
      ten /= 9;
      x *= 10;
    }
  }
  cout << n << endl;
}
