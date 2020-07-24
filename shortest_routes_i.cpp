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

int main() {
  IOS
  ll n, m; cin>>n>>m;
  vector<map<ll, ll> > g(n+1);
  for(int i = 0; i < m; ++i) {
    ll a, b, c; cin>>a>>b>>c;
    g[a][b] = g[a][b] == 0 ? c : min(g[a][b], c);
    // g[b][a] = g[b][a] == 0 ? c : min(g[b][a], c);
  }
  // queue<pii> q;q.push({0, 1});
  vi v(n + 1);
  vi ans(n + 1);
  ans[1] = 0;
  priority_queue<pii> pq;
  pq.push({0, 1});
  ll cnt = 0;
  while(pq.size()) {
    ll node = pq.top().second, price = pq.top().first; pq.pop();
    if(!v[node]) {
      v[node] = 1;
      ans[node] = -price;
      if(++cnt >= n) break;
    }
    for(auto it : g[node]) {
      ll next = it.first, p = it.second;
      if(v[next]) continue;
      pq.push({ price - p, next});
    }
  }
  for(int i = 1; i <= n; ++i)
    cout<<ans[i]<<" ";
  return 0;
}


