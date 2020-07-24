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
ll dist[maxn];
vector<vector<pair<ll, ll> > > adj(maxn + 1);
ll n;
ll minP;
ll M = 1e9 + 7;
ll ans = 0;
vvi adj2(maxn + 1);

void dfs(ll u) {
  dp[u] = u == n ? 1 : 0;
  vis[u] = 1;
  for(ll v : adj2[u]) {
    if(!vis[v]) {
      dfs(v);
    }
    (dp[u] += dp[v]) %= M;
  }
}

void dfs3(ll u) {
  dp[u] = u == n ? 1 : -1e9;
  vis[u] = 1;
  for(ll v : adj2[u]) {
    if(!vis[v]) {
      dfs3(v);
    }
    dp[u] = max(dp[u], dp[v] + 1);
  }
}


void dfs2(ll u) {
  dp[u] = u == n ? 1 : 1e9;
  vis[u] = 1;
  for(ll v : adj2[u]) {
    if(!vis[v]) {
      dfs2(v);
    }
    dp[u] = min(dp[u], dp[v] + 1);
  }
}

void minPrice(){
  priority_queue<pii> pq;
  pq.push({0, 1});
  while(pq.size()) {
    auto t = pq.top(); pq.pop();
    ll c = t.first, u = t.second;
    if(dist[u] < -c) continue;
    for(auto p : adj[u]) {
      ll v = p.first, c2 = p.second;
      if(-c + c2 < dist[v]){
        dist[v] = -c + c2;
        pq.push({c - c2, v});
      }
    }
  }
}
int main() {
  IOS
  ll m;cin>>n>>m;
  memset(dist, 0x3f, sizeof(dist));
  for(ll i = 0; i < m; ++i)  {
    ll a, b, c; cin>>a>>b>>c;
    adj[a].push_back({b, c});
  }
  dist[1] = 0;
  minPrice();
  for(int i = 1; i <=n ;++i) {
    for(auto p : adj[i]) {
      if(dist[i] + p.second == dist[p.first]) 
        adj2[i].push_back(p.first);
    }
  }
  cout<<dist[n]<<" ";
  dfs(1);
  memset(vis, 0, sizeof(vis));
  // memset(dp, 0, sizseof(dp));
  cout<<dp[1]<<" ";
  dfs2(1);
  cout<<dp[1] - 1<<" ";
  memset(vis, 0, sizeof(vis));
  // memset(dp, 0, sizeof(dp));
  dfs3(1);
  cout<<dp[1] - 1<<" ";
  return 0;
}
