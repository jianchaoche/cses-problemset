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

const int MAXN = 1e5+1;
ll p[MAXN];
map<ll, ll> g;
multiset<ll> cnt;
ll find(ll x) {
  if(p[x] == 0) {
    g[x] = 1;
    cnt.insert(1);
    return p[x] = x;
  }
  return p[x] == x ? x : (p[x] = find(p[x]));
}

bool combine(ll a, ll b) {
  a = find(a); b = find(b);
  if(a != b) {
    p[a] = b;
    cnt.erase(cnt.find(g[a]));
    cnt.erase(cnt.find(g[b]));
    g[b] += g[a];
    cnt.insert(g[b]);
    g.erase(a);
    return true;
  }
  return false;
}
int main() {
  IOS
  ll n, m; cin>>n>>m;
  for(int i = 1; i <= n; ++i) find(i);
  vvi edges;
  for(int i = 0; i < m; ++i) {
    ll a, b; cin>>a>>b;
    // edges.push_back({c, a, b});
    combine(a, b);
    cout<<g.size()<<" "<<*cnt.rbegin()<<endl;
  }
  return 0;
}


