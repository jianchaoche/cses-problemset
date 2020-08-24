#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7, maxn= 1e6 + 1;
ll inv[maxn + 1];
ll f[maxn + 1], f2[maxn + 1], dp[maxn + 1];
int main() {
  ll n, m; cin>>n;

  inv[1] = 1;
  inv[0] = 1;
  f[0] = 1;
  f2[0] = 1;
  ll p = M;
  for (int i = 2; i <= maxn; i++) {
    inv[i] = ((p - p / i) * inv[p % i]) % p;
  }
  for(ll i = 1; i <= maxn; ++i) {
    f[i] = (i * f[i - 1]) % M;
    f2[i] = (f2[i - 1] * inv[i]) % M;
  }
  dp[0] = 1;
  // dp[1] = 1;
  for(ll i = 2; i <= n; ++i) {
    dp[i] = (i - 1) * dp[i - 2] % M +  (i - 1)* dp[i - 1]  % M;
    dp[i] %= M;
  }
  cout<<dp[n]<<endl;
  return 0;
}
