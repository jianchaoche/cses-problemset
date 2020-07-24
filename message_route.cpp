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

/*
  
5 5
1 2
1 3
1 4
2 3
5 4
*/


int main() {
  IOS
  ll m, n; cin>>n>>m;
  set<ll> edge[n + 1];
  for(int i = 0; i < m; ++i) {
    ll a, b; cin>>a>>b;
    edge[a].insert(b);
    edge[b].insert(a);
  }
  vi path(n);
  queue<ll > q;
  q.push(1);
  path[1] = 1;
  bool res = false;
  vi ans;
  while(q.size()) {
    ll c = q.front(); q.pop();
    if(c == n) {
      res = true;
      break;
    }
    for(auto next : edge[c]) {
      if(path[next]) continue;
      path[next] = c;
      q.push(next);
    }
  }
  if(!res) {
    cout<<"IMPOSSIBLE"; return 0;
  }
  ll p = n;
  while(p != 1) {
    ans.push_back(p);
    p = path[p];
  }
  ans.push_back(1);
  reverse(ans.begin(), ans.end());
  cout<<ans.size()<<endl;
  for(auto x : ans) cout<<x<<" ";
  return 0;
}

