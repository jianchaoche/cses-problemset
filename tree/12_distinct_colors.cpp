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
ll vis[maxn], c[maxn], st[maxn * 8], arr[maxn];
vvi adj(maxn);
ll dt = 0;
ll ans[maxn], sum[maxn], ch[maxn], all = 0, ds[maxn], de[maxn];
ll n, q;
ll f[maxn];
void upd(ll l1, ll x, ll i = 1, ll l2 = 0, ll r2 = n) {
  if(l2 == r2) {
    st[i] += x; return;
  }
  ll mid = (l2 + r2 ) / 2;
  if(l1 <= mid) 
    upd(l1, x, i * 2, l2, mid);
  else 
    upd(l1, x, i * 2 + 1, mid + 1, r2);
  st[i] = st[i * 2] + st[i * 2 + 1];
}

ll qry(ll l1, ll r1, ll i = 1, ll l2 = 0, ll r2 = n) {
  if(l1 <= l2 && r1 >= r2) {
    return st[i];
  }
  if(l1 > r2 || l2 > r1) return 0;
  ll mid = (l2 + r2) / 2;
  return qry(l1, r1, i * 2, l2, mid) + qry(l1, r1, i * 2 + 1, mid + 1, r2);
}

// void upd(ll idx, ll x) {
//   if(idx <= 0) return;
//   for(; idx <= n; idx += idx & -idx) {
//     f[idx] += x;
//   }
// }

// ll qry(ll idx) {
//   ll s = 0;
//   for(; idx >0; idx -= idx & -idx) {
//     s += f[idx];
//   }
//   return s;
// }

map<ll, ll> mp;
void dfs(ll u, ll p) {
  ds[u] = dt++;
  for(auto v : adj[u]) {
    if(v == p) continue;
    dfs(v, u);
  }
  de[u] = dt;
  if(mp.count(arr[u])) {
    upd(mp[arr[u]], -1);
    mp.erase(arr[u]);
    
  }
  mp[arr[u]] = ds[u];
  upd(ds[u], 1);
  ans[u] = qry(ds[u], de[u] - 1);
}

ll M = 1e9 + 7;

int main() {
  IOS
  cin>>n;
  for(int i = 0; i < n; ++i) {
    cin>>arr[i + 1];
    
  }
  for(int i = 2; i <=n; ++i) {
    ll a, b; cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  for(int i = 1; i <= n; ++i)
    cout<<ans[i]<<endl;
  return 0;
}
