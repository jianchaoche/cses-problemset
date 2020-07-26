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
vvi adj(maxn);
vvi adj2(maxn);
bool vis[maxn];
ll coin[maxn];
ll coin2[maxn];
vi rt(maxn);
vi dp(maxn);
vi tp;
void dfs(ll u) {
  if(vis[u]) return;
  vis[u] = 1;
  for(ll v : adj[u]){
    if(vis[v]) continue;
    dfs(v);
  }
  tp.push_back(u);
}

void dfs2(ll u, ll r) {
  if(vis[u]) return;
  vis[u] = 1;
  rt[u] = r;
  coin2[r] += coin[u];
  for(ll v : adj2[u]){
    if(vis[v]) continue;
    dfs2(v, r);
  }
}

ll dfs3(ll u, ll p) {
    ll r = rt[u];
    if(vis[u]) return dp[r];
    vis[u] = 1;
    ll c = rt[p] == r ? 0 : coin2[r];
    ll res = c;
    for(ll v : adj[u]) {
        res = max(res, dfs3(v, u) + c);
    }
    return dp[r] = res;
}

int main() {
  IOS
  ll n, m; cin>>n>>m;
  for(int i = 0; i < n; ++i) {
    cin>>coin[i];
  }
  for(int i = 0; i < m; ++i) {
      int a,b; cin>>a>>b; --a; --b;
      adj[a].push_back(b);
      adj2[b].push_back(a);
  }
  for(int i = 0; i < n; ++i ) {
    dfs(i);
  }
  memset(vis, 0, sizeof(vis));
  for(int i = n - 1; i>= 0; --i) {
    if(!vis[tp[i]]) {
      dfs2(tp[i], i);
    }  
  }
  memset(vis, 0, sizeof(vis));
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
      ans = max(ans, dfs3(i, -1));
  }
  cout<<ans;
  return 0;
}


