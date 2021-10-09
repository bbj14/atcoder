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

const string YES = "Yes";
const string NO = "No";

vvi t;

double katamuki(int a, int b) {
  if (t[a][0] - t[b][0] == 0) return INT_MAX;
  return (double)(t[a][1] - t[b][1]) / (t[a][0] - t[b][0]);
}

// comb(a, b): aからb個選ぶ組み合わせ
bool comb(vector<int> a, int num, int index = 0, vector<int> b = {}) {
  if (b.size() == num) {
    double a1, a2, a3;
    a1 = katamuki(b[0], b[1]);
    a2 = katamuki(b[0], b[2]);
    a3 = katamuki(b[1], b[2]);
    if (a1 == a2 && a2 == a3) return true;
    return false;
  }
  rep(i, index, a.size()) {
    auto next = b;
    next.push_back(a[i]);
    if (comb(a, num, i + 1, next)) return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  t.assign(n, vector<int>(2));
  rep(i, 0, n) cin >> t[i][0] >> t[i][1];

  vector<int> num(n);
  iota(all(num), 0);
  if (comb(num, 3)) yesno;
}
