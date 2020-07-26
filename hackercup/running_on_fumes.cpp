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
  ll T; cin>>T;
  ll CASE = 1;
  while(T--) {
    ll N, M; cin>>N>>M;
    vector<ll> cap(N);
    for(int i = 0; i < N; ++i) {
      cin>>cap[i];
    }
    priority_queue<vi, vvi, greater<vi>> pq;
    ll ans = -1;
    vi vis(N, 1e16);
    pq.push({0, 0, M});
    while(pq.size()) {
      auto &v = pq.top();
      ll cost = v[0], city = v[1], tank = v[2]; pq.pop();
      if(city == N - 1) {ans = cost;break;}
      if(tank == 0 && cap[city] == 0) continue;
      if(tank > 0) {
        pq.push({cost, city + 1, tank - 1});
      }
      if(vis[city] > cost) {
        
        vis[city] = cost;
        if(cap[city] && vis[city + 1] > cost + cap[city]) {
          pq.push({cost + cap[city], city +1, M - 1});
          // vis[city + 1] = cost + cap[city];
        }
      }
    }
    cout<<"Case #"<<CASE++<<": "<<ans<<endl;
  }
  return 0;
}


