#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
//#define F0R(i,a) FOR(i,0,a)
#define INF = 1e18;
#define filli() ll n; cin>>n; ll t = n; vector<ll> arr; while(t--) {ll a; cin>>a; arr.push_back(a);}
#define filli(n, arr) { ll t = n; while(t--) {ll a; cin>>a; arr.push_back(a);} }
#define fills(arr) string a; cin>>a; arr.push_back(a);
#define REP(i, m) for(ll i = 0; i < (m); ++i)
#define acc(arr) accumulate(arr.begin(), arr.end(), 0)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI=acos(-1.0);
const double epsilon=PI/180.0;
typedef vector<string> vs;
typedef long long ll;typedef unsigned int unit32;typedef unsigned long long ull;typedef vector<ll> vi;typedef vector<vector<ll> > vvi;typedef map<ll, ll> mii;typedef map<string, string> mss;typedef map<ll, string> mis;typedef map<string, ll> msi;typedef pair<ll, ll> pii;

const ll maxn = 2e5 + 1;
ll vis[8][8];
vi path(maxn);
vi eu(maxn), ev(maxn);
vi ans;
ll adj[21][21];
ll dp[1<<20][20];
ll M = 1e9 + 7;
bool dfs(ll x, ll y, ll step) {
}
int main() {
  IOS

  ll n, m; cin>>n>>m;
  for(int i = 0; i < m; ++i) {
    int a, b; cin>>a>>b; --a, --b;
    ++adj[a][b];
  }
  dp[1][0] = 1;
  for(int i = 2; i < (1<<n); ++i) {
    if((i >> (n - 1)) && i != (1 << n) - 1) continue;
    for(int j = 0; j < n; ++j) {
      if(i & (1 << j)) {
        int i2 = i ^ (1<<j);
        for(int k = 0; k < n; ++k) {
          if(i2 >> k & 1) {
            dp[i][j] += dp[i2][k] * adj[k][j];
          }
        }
        dp[i][j] %= M;
      }
    }
  }
  cout<<dp[(1<<n) - 1][n - 1];
  return 0;
}
