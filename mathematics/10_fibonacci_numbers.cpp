#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7, maxn= 1e6 + 1;
ll inv[maxn + 1];
ll f[maxn + 1], f2[maxn + 1], dp[maxn + 1];
typedef vector<vector<ll> > vvi;
vvi mul(vvi &a, vvi &b) {
  vvi r = vvi(a.size(), vector<ll>(b[0].size()));
  for(int i = 0; i < a.size(); ++i) {
    for(int k = 0; k < b.size(); ++k) {
      for(int j = 0; j < b[0].size(); ++j) {
        r[i][j] += a[i][k] * b[k][j];
        r[i][j] %= M;
      }
    }
  }
  return r;
}
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
  vvi r = {{0, 1}};
  vvi b = {{0, 1}, {1, 1}};
  while(n) {
    if(n & 1) {
      r = mul(r, b);
    }
    b = mul(b, b);
    n = n >> 1;
  }
  cout<<r[0][0]<<endl;
  return 0;
}
