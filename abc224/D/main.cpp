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
  int m;
  cin >> m;

  vvi G(9);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vi start(9);
  rep(i, 0, 8) {
    int x;
    cin >> x;
    x--;
    start[x] = i + 1;
  }

  vi ok = {1, 2, 3, 4, 5, 6, 7, 8, 0};

  set<vi> store;

  queue<pair<vi, int>> q;
  q.push({start, 0});
  store.insert(start);

  while (q.size()) {
    auto now = q.front();
    q.pop();

    if (now.first == ok) {
      cout << now.second << endl;
      return 0;
    }

    int emp;
    rep(i, 0, 9) {
      if (now.first[i] == 0) emp = i;
    }

    for (auto v : G[emp]) {
      vi next = now.first;
      swap(next[emp], next[v]);

      if (store.count(next)) continue;

      store.insert(next);

      q.push({next, now.second + 1});
    }
  }

  cout << -1 << endl;
}
