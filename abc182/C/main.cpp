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
  string n;
  cin >> n;
  vector<int> a;
  int sum = 0;
  for (char c : n) {
    int num = c - '0';
    a.push_back(num);
    sum += num;
  }

  if (sum % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }

  rep(i, 0, n.size()) {
    int s = 0;
    rep(j, 0, n.size()) {
      if (i == j) continue;
      s += a[j];
    }
    if (s % 3 == 0 && s !=0) {
      cout << 1 << endl;
      return 0;
    }
  }

  rep(i, 0, n.size() - 1) {
    rep(j, i + 1, n.size()) {
      int s = 0;
      rep(k, 0, n.size()) {
        if (i == k || j == k) continue;
        s += a[k];
      }
      if (s % 3 == 0 && s !=0) {
        cout << 2 << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
}
