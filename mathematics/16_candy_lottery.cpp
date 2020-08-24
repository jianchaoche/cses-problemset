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
double dp[101][10101];
int main() {
  ll n, K; cin>>n>>K;
  double ans = 0;
  dp[0][0] = 1;
  for(int i = 0; i < n; ++i) {
    for(int j = i; j <= i * K; ++j) {
      for(int k = 1; k <= K; ++k) {
        dp[i + 1][j + k] += dp[i][j] / K;
      }
    }
  }
  for(int i = n; i <= n * K; ++i) {
    cout<<" i:"<<i<<" "<<dp[n][i] * n<<" "<<endl;
    // 1 3 3 1 2 2
    
    ans = max(ans, dp[n][i]);
  }
  cout<<fixed<<setprecision(6)<<ans<<endl;
  return 0;
}
