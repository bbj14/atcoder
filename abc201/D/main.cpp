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

int A[2100][2100];
int dp[2100][2100];

int main() {
  int H, W;
  cin >> H >> W;

  repe(i, 1, H) {
    repe(j, 1, W) {
      char c;
      cin >> c;
      if (c == '+')
        A[i][j] = 1;
      else
        A[i][j] = -1;
    }
  }

  dp[H][W] = 0;
  for (int i = H; i > 0; i--) {
    for (int j = W; j > 0; j--) {
      if (i == H && j == W) continue;
      if (i == H)
        dp[i][j] = A[i][j + 1] - dp[i][j + 1];
      else if (j == W)
        dp[i][j] = A[i + 1][j] - dp[i + 1][j];
      else
        dp[i][j] = max(A[i + 1][j] - dp[i + 1][j], A[i][j + 1] - dp[i][j + 1]);
    }
  }

  if (dp[1][1] > 0) cout << "Takahashi" << endl;
  if (dp[1][1] < 0) cout << "Aoki" << endl;
  if (dp[1][1] == 0) cout << "Draw" << endl;
}
