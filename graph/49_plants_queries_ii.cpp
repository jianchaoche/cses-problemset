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
ll n,q;
ll vis[maxn];
vi adj[maxn];
ll rt[maxn];
ll d = 1;
ll ds[maxn], de[maxn], cp[maxn], t[maxn], cs[maxn], cycpos[maxn], dt[maxn];
void dfs(ll u) {
  ds[u] = d++;
  for(ll v : adj[u]) {
    if(rt[v] != v) {
      dt[v] = dt[u] + 1;
      rt[v] = rt[u];
      cp[v] = cp[u];
      dfs(v);
    }
  }
  de[u] = d++;
}

ll p[maxn];
int main() {
  IOS
  cin>>n>>q;
  for(ll i = 1; i <= n; ++i) {
    cin>>t[i];
    adj[t[i]].push_back(i);
  }
  memset(rt, -1, sizeof(rt));
  for(int i = 1; i <= n; ++i) {
    if (rt[i] == -1) {
      ll u = i;
      vi cyc;
      
      while(!vis[u]) {
        vis[u] = u;
        p[u] = t[u];
        u = t[u];
      }
      while(!cyc.size() || u != cyc[0]) {
        cycpos[u] = cyc.size();
        cyc.push_back(u);
        rt[u] = u;
        u = t[u];
      }

      for(ll ci : cyc) {
        cs[ci] = cyc.size();
        cp[ci] = i;
        dfs(ci);
      }
    }
  }
  while(q--) {
    ll a, b; cin>>a>>b;
    if(a == b) {
      cout<<0<<endl;
      continue;
    }
    ll ans = -1;
    if(cp[a] == cp[b]) {
      if(rt[b] == b) {
        cout<<dt[a] + ((cs[b] + cycpos[b] - cycpos[rt[a]]) % cs[b])<<endl;
        continue;
      }else if(ds[b]< ds[a] && de[a] < de[b]){
        cout<<dt[a] - dt[b]<<endl;
        continue;
      }
    }
    cout<<ans<<endl;
  }
}
