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

set<ll> loop;
bool vis[10001];
vvi g(10001);
/**
 * 
 * check a node can achive to node n.
*/
bool dfs(ll u, ll e) {
  if(vis[u]) return false;
  if(e == u) return true;
  vis[u] = 1;
  for(auto v : g[u]) {
    if(dfs(v, e)) return true;
  }
  return false;
}

/*
test case:
4 4
1 4 1
2 4 1
2 3 1
3 2 1
dfs2: 
if we can find a loop and also the loop can be arrived from node 1.
*/
void dfs2(ll u, set<ll> &ns) {
  if(vis[u]) return;
  if(loop.count(u)) ns.insert(u);
  vis[u] = 1;
  for(auto v : g[u]) {
    dfs2(v, ns);
  }
}
int main() {
  IOS
  ll n,m; cin>>n>>m;
  vvi edges;
  for(int i = 0; i < m;++i) {
    ll a, b, c; cin>>a >>b>>c;
    edges.push_back({a, b, c});
    g[a].push_back(b);
  }
  vi dp(n+ 1);
  for(int i = 0; i <=n; ++i) dp[i] = -1e17;
  // dp[0] = ; dp[n = 1e18;
  dp[1] = 0;
  vi val1, val2;
  for(int i = 0; i <= n; ++i) {
    for(auto &e : edges) {
      dp[e[1]] = max(dp[e[1]], (ll)e[2] + (ll)dp[e[0]]);
    }
    if(i == n - 1) 
      val1 = dp;
    if(i == n)
      val2 = dp;
  }

  /*
    find all the increasing loop node.
  */
  for(ll i = 1; i <= n; ++i){
    if(val1[i] != val2[i])
      loop.insert(i);
  }
  set<ll> ns;
  /*
    find the loop nodes can be arrived by node 0.  set them to ns.
  */
  dfs2(1, ns);
  if(val1[n] == val2[n]) {
    bool res = false;
    /*
    find out if their is a loop node which is connected to node 1 and node n.
    */
    for(auto u :  ns) {
      memset(vis, 0, sizeof(vis));
      res = res || dfs(u, n);
    }
    if(res) cout<<-1;
    else
    cout<<dp[n]<<endl;
  }else{
    cout<<-1<<endl;
  }
}


