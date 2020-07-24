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

void bfs(vector<vector<pair<ll, ll> > > &adj, ll start, vi &dis) {
  priority_queue<vi> pq;
  vi vis(dis.size());
  pq.push({0, start});
  ll cnt = 1;
  while(pq.size()) {
    auto &v = pq.top(); ll p = v[0], u = v[1]; pq.pop();
    if(!vis[u]) {
      vis[u] = 1;
      dis[u] = -p;
      if(++cnt >= dis.size())
        break;
    }
    
    for(auto &it : adj[u]) {
      ll v = it.first, price = it.second;
      if(vis[v]) continue;
      if(dis[v] > -p + price) {
        dis[v] = -p + price;
        pq.push({p - price, v});
      }
    }
  }
}

int main() {
  IOS
  ll n, m; cin>>n>>m;
  vector<vector<pair<ll, ll> > > adj(n + 1), adj2(n + 1);
  for(int i = 0; i <m; ++i) {
    ll a, b, c; cin>>a>>b>>c;
    adj[a].push_back({b, c});
    adj2[b].push_back({a, c});
  }
  vi dis(n + 1, 1e18), dis2(n + 1, 1e18);
  bfs(adj, 1, dis);
  bfs(adj2, n, dis2);
  ll ans = 1e18;
  for(ll i = 1; i <= n; ++i) {
    ll u = i;
    for(auto &it : adj[i]) {
      ll v = it.first, p = it.second;
      ans = min(ans, dis[u] + dis2[v] + p/2);
    }
  }
  cout<<ans<<endl;
  return 0;
}


