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
  int n;
  cin >> n;
  string s;
  cin >> s;

  int l = 0, r = n - 1;
  int cl = 0, cr = 0;
  while (l < r) {
    while (s[l] != 'W' && l < n) {
      l++;
    }
    if (s[l] == 'W') {
      cl++;
      l++;
    }

    while (s[r] != 'R' && 0 <= r) {
      r--;
    }
    if (s[r] == 'R') {
      cr++;
      r--;
    }
  }
  cout << min(cl, cr) << endl;
}
