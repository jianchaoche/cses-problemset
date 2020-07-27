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

const ll maxn = 2001;
ll vis[maxn];
vi path(maxn);
vvi eu(maxn * 2);
vvi edges(maxn * 2);
vi ans;

ll M = 1e9 + 7;
ll n;
ll dfs(ll u, ll w) {
  if(u == n - 1)  {
    return w;
  }
  if(w == 0) return 0;
  if(vis[u]) return 0;
  vis[u] = 1;
  for(ll e : eu[u]){
    auto &edge = edges[e];
    ll v = edge[1], w2 = edge[2];
    if(w2 == 0) continue;
    if(vis[v]) continue;
    ll f = dfs(v, min(w, w2));
    if(f) {
      edge[2] -= f;
      edges[e ^ 1][2] += f;
      vis[u] = 0;
      return f;
    }
  }
  return 0;
}

vi p;

bool dfs(ll u) {
  if(u == n - 1) return true;
  for(ll e : eu[u]) {
    auto &edge = edges[e];
    ll v = edge[1], w = edge[2];
    if(w == 0 && !vis[e] && (e & 1) == 0) {
      edge[2] = 1;
      vis[e] = 1;
      if(dfs(v)) {
        p.push_back(v);
        return true;
      }
    }
  }
  return false;
}

int main() {
  IOS

  ll m; cin>>n>>m;
  for(int i = 0; i < m; ++i) {
    ll a, b, c; cin>>a>>b; --a, --b;
    edges[i * 2] = {a, b, 1};
    edges[i * 2 + 1] = {b, a, 0};
    eu[a].push_back(i * 2);
    eu[b].push_back(i * 2 + 1);
  }
  ll f = 0;
  while(true) {
    memset(vis, 0, sizeof(vis));
    ll res = dfs(0, 1e18);
    if(res == 0) break;
    f += res;
  }
  cout<<f<<endl;

  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < f; ++i) {
    
    dfs(0);
    p.push_back(0);
    reverse(p.begin(), p.end());
    cout<<p.size()<<endl;
    for(auto x : p)
      cout<<x + 1<<" ";
    cout<<endl;
    p = {};
  }
  return 0;
}
