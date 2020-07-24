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
  ll n, m, k; cin>>n>>m>>k;
  vector<vector<pair<ll, ll>>> adj(n + 1);
  for(int i = 0; i < m; ++i) {
    ll a, b, c; cin>>a>>b >>c;
    adj[a].push_back({b, c});
  }
  priority_queue<pair<ll, ll> > pq;
  pq.push({0, 1});
  vvi d(n + 1);
  while(pq.size()) {
    auto t = pq.top(); pq.pop();
    ll c = t.first, u = t.second;
    if(d[u].size() >= k) {
      // if(u == n) break;
      continue;
    }
    // cout<<"u: "<<c<<endl;
    d[u].push_back(-c);
    for(auto &p : adj[u]) {
      ll v = p.first, c2 = p.second;
      pq.push({c - c2, v});
    }
  }
  for(int i = 0; i < d[n].size(); ++i) {
    cout<<d[n][i]<<" ";
  }
  return 0;
}


