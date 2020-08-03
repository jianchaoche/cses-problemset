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
ll vis[maxn], c[maxn];
vvi adj(maxn);
ll d[maxn];
ll ans[maxn], sum[maxn], ch[maxn], all = 0;
 
ll f[32][maxn];
void dfs(ll u, ll p) {
  // f[0][u] = p;
  // for(ll i = 1; i < 20; ++i) {
  //   f[i][u] = f[i - 1][f[i - 1][u]];
  // }
  for(auto v : adj[u]) {
    if(v == p) continue;
    f[0][v] = u;
    d[v] = d[u] + 1;
    dfs(v, u);
  }
  
}
 
void dfs2(ll u, ll p) {
  for(auto v : adj[u]) {
    if(v == p) continue;
    dfs2(v, u);
    c[u] += c[v];
  }
}
ll lca(ll u, ll v) {
  if(d[u] < d[v]) swap(u, v);
  for(ll i =19; ~i; --i) {
    if(d[u] - (1 << i) >= d[v])
      u = f[i][u];
  }
  if(u == v) return u;
  for(ll i = 19; ~i; --i) {
    if(f[i][u] != f[i][v]) {
      u = f[i][u];
      v = f[i][v];
    }
  }
  return f[0][u];
}
ll M = 1e9 + 7;
ll n, q;
int main() {
  IOS
  cin>>n>>q;
  for(int i = 2; i <= n; ++i) {
    ll a, b; cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  for(int i = 1; i < 20; ++i) {
    for(int j = 1; j <=n ; ++j)
      f[i][j] = f[i - 1][f[i - 1][j]];
  }
  while(q--) {
    ll a, b; cin>>a>>b;
    ll anc = lca(a, b);
    ++c[a]; ++c[b];
    --c[anc]; --c[f[0][anc]];
  }
  dfs2(1, 0);
  for(int i =1 ; i <= n; ++i) {
    cout<<c[i]<<" ";
  }
  return 0;
}