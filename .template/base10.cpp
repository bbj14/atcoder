// K 進法表記の S を、10 進法表記に変換する
ll base10(string s, ll k) {
  ll ans = 0;
  for (char x : s) {
    ans *= k;
    ans += x - '0';
  }
  return ans;
}