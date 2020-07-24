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

/**
 * 
4 2
1 2
3 4
*/
const int maxn = 1e5 + 1, maxm = 2e5 + 1;
ll parent[maxn];
set<ll> g;
ll find(int x) {
  if(parent[x] == 0) 
    g.insert(x);
  return parent[x] == 0 ? x : (parent[x] = find(parent[x]));
}

void combine(ll a, ll b) {
  a = find(a); b = find(b);
  if(a != b) {
    parent[a] = b;
    g.erase(a); g.insert(b);
  }
}

int main() {
  IOS
  ll n, m; cin>>n>>m;
  for(int i = 1; i <= n; ++i)
    find(i);
  for(int i = 0; i < m; ++i) {
    ll a, b; cin>>a>>b;
    combine(a, b);
  }
  cout<<g.size() - 1<<endl;
  if(g.size() < 2) return 0;
  for(auto it = next(g.begin()); it != g.end(); ++it) {
    auto pv = prev(it);
    cout<<*pv<<" "<<*it<<endl;
  }
  return 0;
}


