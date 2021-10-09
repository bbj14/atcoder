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
  string s;
  cin >> s;

  int k = s.size();

  ll sum = 0;

  ll x = 9;
  rep(i, 0, (k - 1) / 2) {
    sum += x;
    x *= 10;
  }

  if (k % 2 == 0) {
    int left = stoi(s.substr(0, k / 2));
    int right = stoi(s.substr(k / 2));

    if (left > right) left--;

    sum += max(0, left - (int(pow(10, k / 2 - 1)) - 1));
  }

  cout << sum << endl;
}
