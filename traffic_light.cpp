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
  vector<ll> arr;
  filli(m, arr);
  map<ll, ll> position, dis;
  // vi ans;
  position[0] = 1; position[n] = 1;
  dis[n] = 1;
  for(auto pos : arr) {
    auto it = position.upper_bound(pos);
    auto pv = prev(it);
    int d = it->first - pv->first;
    if(--dis[d] == 0) dis.erase(d);
    position[pos] = 1;
    ++dis[it->first - pos];
    ++dis[pos - pv->first];
    cout<<dis.rbegin()->first<<" ";
  }
  return 0;
}


