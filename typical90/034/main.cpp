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

int n, k;
vi a;

bool solve(int m) {
  map<int, int> mp;
  rep(i, 0, n) {
    mp[a[i]]++;
    if (i < m - 1) continue;
    if (i != m - 1 && --mp[a[i - m]] == 0) mp.erase(a[i - m]);
    if (mp.size() <= k) return true;
  }
  return false;
}

int main() {
  cin >> n >> k;

  a = vi(n);
  rep(i, 0, n) cin >> a[i];

  int ok = 1, ng = n + 1;
  while (abs(ok - ng) > 1) {
    int mid = (ng + ok) / 2;
    if (solve(mid))
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
}
