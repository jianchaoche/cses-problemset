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
ll vis[maxn];
ll adj[maxn];
ll rt[maxn];
ll root[maxn];
ll cycpos[maxn];
ll tocyc[maxn];
ll chain[maxn];
ll cycsize[maxn];
ll n;

ll dfs(ll u, ll r) {
  if(rt[u]) return -2;
  if(vis[u]) {
    rt[u] = r;
    cycpos[u] = 1; return 1;
  }
  vis[u] = 1;
  ll pos = dfs(adj[u], r) + 1;
  if(pos < 0) return -2;
  if(cycpos[u]) {
    cycsize[r] = pos - 2;
    return -2;
  }
  cycpos[u] = pos;
  rt[u] = r;
  return pos + 1;
}



pair<ll, ll> dfs2(ll u, ll r) {
  if(rt[u]) {
    root[rt[u]] = r;
    return {u, 0};
  }
  root[u] = r;
  auto res = dfs2(adj[u], r);
  tocyc[u] = res.first;
  chain[u] = res.second + 1;
  return {res.first, res.second + 1};
}

int main() {
  IOS
  ll q; cin>>n>>q;
  vi in(n + 1);
  for(int i = 1; i <= n; ++i) {
    cin>>adj[i];
    ++in[adj[i]];
  }
  for(int i = 1; i <= n; ++i) {
    if(!vis[i])
      dfs(i, i);
  }
  memset(vis, 0, sizeof(vis));
  for(int i = 1; i <= n; ++i) {
    if(in[i] == 0) {
      dfs2(i, i);
    }
  }
  // cout<<"rt: ";
  // for(ll i = 1; i<=n; ++i) {
  //   cout<<rt[i]<<" ";
  // }
  // cout<<"chain: ";
  // for(ll i = 1; i<=n; ++i) {
  //   cout<<chain[i]<<" ";
  // }
  // cout<<"cycpos: ";
  // for(ll i = 1; i<=n; ++i) {
  //   cout<<cycpos[i]<<" ";
  // }
  // cout<<"cycsize: ";
  // for(ll i = 1; i<=n; ++i) {
  //   cout<<cycsize[i]<<" ";
  // }
  // cout<<endl;
  while(q--) {
    ll a, b; cin>>a>>b;
    if(root[rt[a] ? rt[a] : a] != root[rt[b] ? rt[b] : b]) {
      cout<<-1<<endl;
      continue;
    }
    if(rt[a] && !rt[b]) {
      cout<<-1<<endl;
      continue;
    }
    if(!rt[a] && !rt[b]) { 
      if(chain[a] < chain[b])
        cout<<-1<<endl;
      else
        cout<<chain[a] - chain[b]<<endl;
      continue;
    }
    // cout<<"final"<<endl;
    ll dis = 0;
    ll src = a;
    if(!rt[a]) {
      dis = chain[a];
      a = tocyc[a];
    }
    ll size = cycsize[rt[b]];
    // cout<<size<<" :size  to cyc:"<<tocyc[src]<<endl;
    cout<<((size + cycpos[b] - cycpos[a]) % size) + dis<<endl;
  }
  return 0;
}
