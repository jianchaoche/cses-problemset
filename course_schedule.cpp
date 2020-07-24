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
 
const int MAXN = 1e5 + 1;
vvi adj(MAXN);
bool vis[MAXN];
bool vis2[MAXN];
vi ans;
bool dfs(ll u) {
  if(vis[u]) return false;
  vis[u] = 1;
  vis2[u] = 1;
  for(ll v : adj[u]){
    if(vis[v]) return false;
    if(vis2[v]) continue;
    if(!dfs(v)) return false;
  }
  ans.push_back(u);
  vis[u] = 0;
  return true;
}
int main() {
  IOS
  ll n, m; cin>>n>>m;
  
  for(int i = 0; i < m; ++i) {
    ll a, b; cin>>a>>b;
    adj[a].push_back(b);
  }
  for(ll i = 1; i <= n; ++i) {
    if(!vis2[i])
      if(!dfs(i)){
        cout<<"IMPOSSIBLE";return 0;
      }
  }
  reverse(ans.begin(), ans.end());
  for(ll x : ans) cout<<x<<" ";
  return 0;
}
 