#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7, maxn= 1e6 + 1;
ll inv[maxn + 1];
ll f[maxn + 1], f2[maxn + 1];
int main() {
  ll n; cin>>n;
  ll ans = 0;
  inv[1] = 1;
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
  while(n--) {
    ll a, b; cin>>a>>b;
    cout<<(((f[a] * f2[b])% M) * f2[a-b]) % M <<endl;
  }
  return 0;
}
