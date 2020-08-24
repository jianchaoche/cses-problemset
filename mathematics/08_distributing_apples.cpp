#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7, maxn= 2e6 + 1;
ll inv[maxn + 1];
ll f[maxn + 1], f2[maxn + 1];
int main() {
  ll n, m; cin>>n>>m;

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
  ll ans = ((f[n + m - 1] * f2[m]) %M ) * f2[n - 1];
  cout<<ans%M<<endl;
  return 0;
}
