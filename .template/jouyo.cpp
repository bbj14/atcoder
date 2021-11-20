using ll = long long;

// 【標準ライブラリあり】
// Euclid の互除法
// a,bの最大公約数
template <class T>
T GCD(T a, T b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}

// 【ACLあり】
// 繰り返し自乗法
// a^n をmで割った余り
ll powmod(ll a, ll n, ll m) {
  if (n == 0) return 1;
  ll half = powmod(a, n / 2, m);
  ll res = half * half % m;
  if (n & 1) res = res * a % m;
  return res;
}