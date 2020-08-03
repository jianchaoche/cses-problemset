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
ll vis[maxn];
vvi tree(maxn);
map<ll, ll> pr;
ll out[maxn];
ll M = 1e9 + 7;
ll n;
ll dp0[maxn], dp1[maxn];

void dfs(ll u = 0, ll p = 0) {
  for(auto v : tree[u]) {
    if(v == p) continue;
    dfs(v, u);
    dp1[u] = max(dp1[u] + max(dp0[v], dp1[v]), dp0[v] + dp0[u] + 1);
    dp0[u] += max(dp0[v], dp1[v]);
  }
}
int main() {
  IOS
  cin>>n;
  
  for(int i = 2; i <=n; ++i) {
    ll p, c; cin>>p>>c;
    tree[p].push_back(c);
    tree[c].push_back(p);
  }
  dfs(1, 0);
  cout<<max(dp0[1], dp1[1])<<endl;
  return 0;
}
