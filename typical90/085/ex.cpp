#include <bits/stdc++.h>

#define For(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rFor(i, a, b) for (int i = (int)(a)-1; i >= (int)(b); --i)
#define rep(i, n) For(i, 0, (n))
#define rrep(i, n) rFor(i, (n), 0)
#define fi first
#define se second

using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;

template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
T div_floor(T a, T b) {
  if (b < 0) a *= -1, b *= -1;
  return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T div_ceil(T a, T b) {
  if (b < 0) a *= -1, b *= -1;
  return a > 0 ? (a - 1) / b + 1 : a / b;
}

template <typename T>
struct coord_comp {
  vector<T> v;
  bool sorted = false;

  coord_comp() {}

  int size() { return v.size(); }

  void add(T x) { v.push_back(x); }

  void build() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sorted = true;
  }

  int get_idx(T x) {
    assert(sorted);
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  }

  T &operator[](int i) { return v[i]; }
};

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 200010;

int main() {
  lint K;
  scanf("%lld", &K);

  vector<pll> ps;
  for (lint i = 2; i * i <= K; ++i) {
    if (K % i == 0) {
      lint cnt = 0;
      while (K % i == 0) {
        ++cnt;
        K /= i;
      }
      ps.emplace_back(i, cnt);
    }
  }
  if (K > 1) ps.emplace_back(K, 1);

  lint ans = 0;
  {
    lint tmp = 1;
    for (auto [num, cnt] : ps) {
      tmp *= (cnt + 2) * (cnt + 1) / 2;
    }
    ans += tmp;
  }
  {
    bool flag = true;
    for (auto [num, cnt] : ps)
      if (cnt % 3 != 0) {
        flag = false;
        break;
      }
    if (flag) ans += 2;
  }
  {
    lint tmp = 1;
    for (auto [num, cnt] : ps) {
      tmp *= cnt / 2 + 1;
    }
    ans += tmp * 3;
  }

  printf("%lld\n", ans / 6);
}