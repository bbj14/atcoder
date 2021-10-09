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

int diff(string s, string t) {
  int cnt = 0;
  rep(i, 0, t.size()) {
    if (s[i] != t[i]) cnt++;
  }
  return cnt;
}

int main() {
  int n, k;
  cin >> n >> k;
  string s, t;
  cin >> s;

  set<char> S;
  for (auto c : s) S.insert(c);

  while (S.size()) {
    for (auto c : S) {
      string x = t + c;
      int d = diff(s, x);

      if (ok) {
        t += c;
        S.erase(c);
        break;
      }
    }
  }
}
