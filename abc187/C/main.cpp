// clang-format off
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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// clang-format on

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, 0, n) {
    string x;
    cin >> x;
    reverse(all(x));
    s[i] = x;
  }

  sort(all(s));

  rep(i, 0, n - 1) {
    if (s[i] + '!' == s[i + 1]) {
      string x = s[i];
      reverse(all(x));
      cout << x << endl;
      return 0;
    }
  }

  cout << "satisfiable" << endl;
}
