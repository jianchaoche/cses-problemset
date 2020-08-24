#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7, maxn= 1e6 + 1;
ll inv[maxn + 1];
ll f[maxn + 1], f2[maxn + 1];
typedef vector<vector<ll> > vvi;
vvi mul(vvi &a, vvi &b) {
  vvi r = vvi(a.size(), vector<ll>(b[0].size(), 1e18 + 100));
  for(int i = 0; i < a.size(); ++i) {
    for(int k = 0; k < b.size(); ++k) {
      for(int j = 0; j < b[0].size(); ++j) {
        r[i][j] = min(r[i][j], a[i][k] + b[k][j]);
        // r[i][j] %= M;
      }
    }
  }
  return r;
}
double dp[101][606];
int main() {
  ll n, a, b; cin>>n>>a>>b;
  double ans = 0;
  dp[0][0] = 1;
  for(int i = 0; i < n; ++i) {
    for(int j = i; j <= i * 6; ++j) {
      for(int k = 1; k <= 6; ++k) {
        dp[i + 1][j + k] += dp[i][j] / 6.0;
      }
    }
  }
  for(int i = a; i <= b; ++i)
    ans += dp[n][i];
  cout<<fixed<<setprecision(6)<<ans<<endl;
  return 0;
}
