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

vi adj[MAXN];
bool vis[MAXN];
bool vis2[MAXN];
ll p[MAXN];
void dfs(ll u) {
  vis2[u] = 1;
  vis[u] = 1;
  for(ll v : adj[u] ) {
    if(vis[v]){
      ll u2 = u;
      vi ans;
      ans.push_back(v);
      while(u != v) {
        ans.push_back(u);
        u = p[u];
      }
      ans.push_back(v);
      cout<<ans.size()<<endl;
      reverse(ans.begin(), ans.end());
      for(auto n : ans) cout<<n<<" ";
      exit(0);
    }else{
      p[v] = u;
      dfs(v);
    }
    
  }
  vis[u] = 0;
}
int main() {
  IOS
  ll n, m; cin>>n>>m;
  for(int i = 0; i < m; ++i) {
    int a, b; cin>>a>>b;
    adj[a].push_back(b);
  }
  for(int i = 1; i <= n; ++i) {
    if(!vis2[i]) {
      dfs(i);
    }
  }
  cout<<"IMPOSSIBLE";
  return 0;
}


