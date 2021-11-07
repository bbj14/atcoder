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

const string YES = "Yes";
const string NO = "No";

int main() {
  int n;
  cin >> n;
  vi a(n);
  rep(i, 0, n) cin >> a[i];

  ll sum = 0;
  rep(i, 0, n) {
    sum += a[i];
    a.push_back(a[i]);
  }

  if (sum % 10 != 0) {
    cout << NO << endl;
    return 0;
  }

  sum /= 10;

  ll left = 0, s = 0;
  rep(i, 0, n * 2) {
    s += a[i];
    while (s > sum && left < i) {
      s -= a[left];
      left++;
    }
    if (s == sum) {
      cout << YES << endl;
      return 0;
    }
  }

  cout << NO << endl;
}