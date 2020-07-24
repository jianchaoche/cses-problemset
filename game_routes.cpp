#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
//#define F0R(i,a) FOR(i,0,a)
#define INF = 1e18;
#define filli() ll n; cin>>n; ll t = n; vector<ll> arr; while(t--) {ll a; cin>>a; arr.push_back(a);}
#define fills(arr) string a; cin>>a; arr.push_back(a);
#define REP(i, m) for(ll i = 0; i < (m); ++i)
#define acc(arr) accumulate(arr.begin(), arr.end(), 0)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI=acos(-1.0);
const double epsilon=PI/180.0;
typedef vector<string> vs;
typedef long long ll;typedef unsigned int unit32;typedef unsigned long long ull;typedef vector<ll> vi;typedef vector<vector<ll> > vvi;typedef map<ll, ll> mii;typedef map<string, string> mss;typedef map<ll, string> mis;typedef map<string, ll> msi;typedef pair<ll, ll> pii;

const ll maxn = 1e5 + 1;
ll dp[maxn];
bool vis[maxn];
vvi adj(maxn + 1);
ll n;
ll M = 1e9 + 7;
ll ans = 0;
void dfs(ll u) {
  if(u == n) {
    dp[u] = 1;
    return;
  }
  vis[u] = 1;
  for(ll v : adj[u]) {
    if(!vis[v]) 
      dfs(v);
    dp[u] += dp[v];
    dp[u] %= M;
  }
}
int main() {
  IOS
  ll m;cin>>n>>m;
  
  for(ll i = 0; i < m; ++i)  {
    ll a, b; cin>>a>>b;
    adj[a].push_back(b);
  }
  dfs(1);
  cout<<dp[1];
  return 0;
}