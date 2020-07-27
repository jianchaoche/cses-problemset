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
vi adj(maxn);
vvi comp(maxn);
vi rt(maxn);
vi vis(maxn);
vi dfn(maxn);
vi cr(maxn);
vi tp;
ll dfs(ll u, ll d = 1) {
  if(vis[u]) {
    if(cr[u]) return u;
    cr[u] = d - vis[u]; 
    return u;
  }
  vis[u] = d;
  if(cr[adj[u]]) {
    cr[u] = cr[adj[u]] + 1;
    return u;
  }
  ll c = dfs(adj[u], d + 1);
  if(vis[c] <= d){
    cr[u] = cr[c];
    return c;
  } 
  else {
    cr[u] = cr[adj[u]] + 1;
    return u;
  }
}


int main() {
  IOS

  ll n, m; cin>>n;
  vi in(maxn);
  for(int i = 0; i < n; ++i) {
    ll a; cin>>a;
    adj[i+ 1] = a;
    ++in[a];
  }
  for(int i = 1; i <= n; ++i) {
    if(in[i] == 0 && !vis[i])
      dfs(i, 1);
  }
  for(int i = 1; i <= n; ++i) {
    if(in[i] == 1 && !vis[i])
      dfs(i, 1);
  }
  for(int i = 1; i <=n; ++i) {
    cout<<cr[i]<<" ";
  }
  return 0;
}
