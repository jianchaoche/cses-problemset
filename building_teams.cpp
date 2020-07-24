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

const int maxn = 1e5 + 1;
set<ll> f[maxn + 1];
ll cols[maxn + 1];
bool dfs(ll n, ll c) {
  if(cols[n]) return cols[n] == c;
  cols[n] = c;
  for(auto next : f[n]) {
    if(!dfs(next, -c)) return false;
  }
  return true;
}

int main() {
  IOS
  ll m, n; cin>>n>>m;
  
  for(int i = 0; i < m; ++i) {
    ll a, b; cin>>a>>b;
    f[a].insert(b);
    f[b].insert(a);
  }
  
  bool res = true;
  for(ll i = 1; i <= n; ++i) {
    if(!cols[i] ){
      if(!dfs(i, 1)) {
        res = false;
        break;
      }
    }
  }
  if(!res) {
    cout<<"IMPOSSIBLE";
    return 0;
  }
  for(int i = 1; i <=n; ++i) {
    cout<<(cols[i] != 1 ? 2 : 1)<<" ";
  }
  return 0;
}

