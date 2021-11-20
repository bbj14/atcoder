// clang-format off
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, m, n) for (int i = m; i < (int)(n); i++)
#define repe(i, m, n) for (int i = m; i <= (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// clang-format on

// perm(a): aの順列
void perm(vector<int> a, vector<int> b = {}) {
  if (a.size() == 0) {
    rep(i, 0, b.size()) { cout << b[i] << " "; }
    cout << endl;
    return;
  }
  rep(i, 0, a.size()) {
    auto remain = a;
    auto next = b;
    next.push_back(a[i]);
    remain.erase(remain.begin() + i);
    perm(remain, next);
  }
}

// permnum(a, b): aからb個選ぶ順列
void permnum(vector<int> a, int num, vector<int> b = {}) {
  if (b.size() == num) {
    rep(i, 0, b.size()) { cout << b[i] << " "; }
    cout << endl;
    return;
  }
  rep(i, 0, a.size()) {
    auto remain = a;
    auto next = b;
    next.push_back(a[i]);
    remain.erase(remain.begin() + i);
    permnum(remain, num, next);
  }
}

// comb(a, num): aからnum個選ぶ組み合わせ
void comb(vector<int> a, int num, int index = 0, vector<int> b = {}) {
  if (b.size() == num) {
    rep(i, 0, b.size()) { cout << b[i] << " "; }
    cout << endl;
    return;
  }
  rep(i, index, a.size()) {
    auto next = b;
    next.push_back(a[i]);
    comb(a, num, i + 1, next);
  }
}

// 二項係数
ll c[100][100];
c[0][0] = 1;
rep(i, 0, 60) repe(j, 0, i) {
  c[i + 1][j] += c[i][j];
  c[i + 1][j + 1] += c[i][j];
}

int main() {
  vector<int> a = {1, 2, 3, 4};
  comb(a, 2);
}