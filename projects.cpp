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

const ll MAXN = 2e5 + 1;
ll dp[MAXN];
ll dfs(vvi &arr, ll idx, ll d) {
  if(idx >= arr.size()) return 0;
  if(dp[idx]) return dp[idx];
  ll res = 0;
  if(arr[idx][1] > d)
    res = dfs(arr, idx + 1, arr[idx][0]) + arr[idx][2];
  res = max(dfs(arr, idx + 1, d), res);
  return dp[idx] = res;
}

int main() {
  IOS
  ll n; cin>>n;
  vvi arr(n);
  for(ll i = 0; i < n; ++i) {
    ll a, b, c; cin>>a>>b>>c;
    arr[i] = {b, a, c};
  }
  sort(arr.begin(), arr.end());
  map<ll, ll> m;
  ll ans = 0;
  m[0] = 0;
  for(ll i = 0; i < n; ++i) {
    auto it = m.lower_bound(arr[i][1]);
    if(it != m.begin()) {
      --it;
      m[arr[i][0]] = max(ans, arr[i][2] + it->second);
      ans = m[arr[i][0]];
    }
  }
  cout<<ans;
  return 0;
}


