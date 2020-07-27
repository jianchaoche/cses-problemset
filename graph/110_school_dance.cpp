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

const ll maxn = 5010;
ll vis[maxn];
ll mt[maxn];
vi adj[maxn];
ll s, t;

bool dfs(ll u) {
  vis[u] = 1;
  for(ll v : adj[u]) {
    if(mt[v] < 0 || (!vis[mt[v]] && dfs(mt[v]))) {
      mt[v] = u;
      return 1;
    }
  }
  return 0;
}
ll n;

int main() {
  IOS

  ll m, k; cin>>n>>m>>k;
  
  for(int i = 0; i < k; ++i) {
    ll a, b; cin>>a>>b; --a; --b;
    adj[a].push_back(b);
  }
  ll ans = 0;
  memset(mt, -1, sizeof(mt));
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < n; ++i) {
    ans += dfs(i);
    memset(vis, 0, sizeof(vis));
  }
  cout<<ans<<endl;
  for(int i = 0; i < m; ++i) {
    if(~mt[i]) {
      cout<<mt[i] + 1<<" "<<i + 1<<endl;
    }
  }
  return 0;
}
