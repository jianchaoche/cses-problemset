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
ll dis[maxn];
bool vis[maxn];
bool vis2[maxn];
ll pu[maxn];
vi adj[maxn];
ll p[maxn];
ll n;
void dfs(ll u) {
  dis[u] = u == n ? 1 : -10000000;
  if(u == n) return;
  vis[u] = 1;
  vis2[u] = 1;
  
  for(ll v : adj[u]) {
    if(!vis2[v]){
      dfs(v);
    }
    if(vis[v]){
      cout<<"IMPOSSIBLE"; exit(0);
    } 
    if(dis[v] + 1 > dis[u]) {
      p[u] = v;
      dis[u] = dis[v] + 1;
    }
  }
  vis[u] = 0;
}
int main() {
  IOS
  ll m; cin>>n>>m;
  
  for(int i = 0; i < m;++i) {
    ll a, b; cin>>a >>b;
    adj[a].push_back(b);
  }
  dfs(1);
  if(dis[1] <= -1) {cout<<"IMPOSSIBLE";  return 0; }
  ll u = 1;
  vi ans;
  while(u != n) {
    ans.push_back(u);
    u = p[u];
  }
  ans.push_back(n);
  cout<<ans.size()<<endl;
  // reverse(ans.begin(), ans.end());
  for(auto x : ans)cout<<x<<" ";
  return 0;
}


