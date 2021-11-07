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
  int n, q;
  cin >> n >> q;

  vi li(n + 1);
  vi rli(n + 1);

  rep(i, 0, q) {
    int a;
    cin >> a;

    if (a != 3) {
      int x, y;
      cin >> x >> y;

      if (a == 1) {
        li[x] = y;
        rli[y] = x;
      } else {
        li[x] = 0;
        rli[y] = 0;
      }
    } else {
      int x;
      cin >> x;

      vi ans;
      int now = x;

      while (true) {
        if (rli[now] == 0) {
          break;
        }
        now = rli[now];
      }

      while (true) {
        ans.push_back(now);
        if (li[now] == 0) break;
        now = li[now];
      }

      cout << ans.size() << " ";
      for (auto i : ans) {
        cout << i << " ";
      }
      cout << "\n";
    }
  }
}
