#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7, maxn= 1e6 + 1;
ll inv[maxn + 1];
ll f[maxn + 1], f2[maxn + 1];
typedef vector<vector<ll> > vvi;
double dp[101][8][8];
double ans[8][8];
int main() {
  
  int K; cin>>K;
  for(int i = 0; i < 8; ++i) 
    for(int j = 0; j < 8; ++j) 
        ans[i][j] = 1;
  for(int i = 0; i < 8; ++i) {
    for(int j = 0; j < 8; ++j) {
      memset(dp, 0, sizeof(dp));
      dp[0][i][j] = 1;
      for(int k = 0; k < K; ++k) {
        for(int i1 = 0; i1 < 8; ++i1) {
          for(int j1 = 0; j1 < 8; ++j1) {
            int nd = (i1 < 7) + (i1 > 0) + (j1 < 7) + (j1 > 0);
            if(i1 < 7)
              dp[k + 1][i1 + 1][j1] += dp[k][i1][j1] / nd;
            if(i1)
              dp[k + 1][i1 - 1][j1] += dp[k][i1][j1] / nd;
            if(j1 < 7)
              dp[k + 1][i1][j1 + 1] += dp[k][i1][j1] / nd;
            if(j1)
              dp[k + 1][i1][j1 - 1] += dp[k][i1][j1] / nd;
          }
        }
      }
      int cnt = 1;
      for(int i1 = 0; i1 < 8; ++i1) {
        for(int j1 = 0; j1 < 8; ++j1) {
          ans[i1][j1] *= (1 - dp[K][i1][j1]);
        }
      }
    }
  }
  double a2 = 0;
  for(int i = 0; i < 8; ++i) {
    for(int j = 0; j < 8; ++j) {
      a2 += ans[i][j];
    }
  }
  cout<<fixed<<setprecision(6)<<a2<<endl;
  return 0;
}
