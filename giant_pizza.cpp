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

void dfs2(ll u, vi &arr) {
  if(vis[u]) return;
  vis[u] = 1;
  for(ll v : adj2[u]){
    if(vis[v]) continue;
    dfs2(v, arr);
  }
  arr.push_back(u);
}

int main() {
  IOS
  ll n, m; cin>>n>>m;
  for(int i = 0; i < m; ++i) {
    char c1, c2; ll u1, u2;
    cin>>c1>>u1>>c2>>u2;
    u1 *= 2; u2 *= 2;

  }
}


