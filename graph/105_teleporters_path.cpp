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
vi vis(maxn);
vi path(maxn);
vi eu(maxn), ev(maxn);
vi ans;
ll n, m,f = 0;
vi in(maxn), out(maxn);
void dfs(ll u) {
  while(adj[u].size()) {
    auto e = adj[u].back(); adj[u].pop_back();
    if(vis[e]) continue;
    vis[e] = 1;
    dfs(eu[e] ^ ev[e] ^ u);
    ans.push_back(u);
  }
}
int main() {
  IOS
  cin>>n>>m;
  for(int i = 0; i < m; ++i) {
      cin>>eu[i]>>ev[i]; --eu[i], --ev[i];
      ++in[ev[i]]; ++out[eu[i]];
      adj[eu[i]].push_back(i);
  }
  for(int i = 1; i < n-1; ++i) {
    if(in[i] != out[i]) {
      cout<<"IMPOSSIBLE"; return 0;
    }
  }
  if(abs(in[0] - out[0]) > 1 || abs(in[n-1] - out[n-1] > 1) ) {cout<<"IMPOSSIBLE"; return 0;}
  if(in[0] > out[0] == in[n-1] > out[n-1]) {cout<<"IMPOSSIBLE"; return 0;}
  ll cnt = 0;
  dfs(0);
  reverse(ans.begin(), ans.end());
  ans.push_back(n-1);
  if(ans.size() ^ (m + 1)) {cout<<"IMPOSSIBLE"; return 0;}
  for(auto x : ans) cout<<x + 1<<" ";
  return 0;
}
