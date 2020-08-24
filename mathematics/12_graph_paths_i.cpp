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
  ll n, m, k; cin>>n>>m>>k;
  vvi r(n, vector<ll>(n));
  vvi b(n, vector<ll>(n));
  for(int i = 0; i < m; ++i) {
    ll u, v;cin>>u>>v; --u; --v;
    b[u][v] += 1;
  }
  // for(auto row : b) {
  //   for(auto x : row) cout<<x<<" ";
  //   cout<<endl;
  // }
  for(int i = 0; i < n; ++i) r[i][i] = 1;
  while(k) {
    if(k & 1) {
      r = mul(r, b);
    }
    b = mul(b, b);
    k = k >> 1;
  }
  // for(auto row : b) {
  //   for(auto x : row) cout<<x<<" ";
  //   cout<<endl;
  // }
  cout<<r[0][n - 1]<<endl;
  return 0;
}
