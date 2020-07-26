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

ll adj[51][51];

int main() {
  IOS
  ll T; cin>>T;
  ll CASE = 1;
  while(T--) {
    ll N; cin>>N;
    map<ll, ll> dp;
    vector<pair<ll, ll> > trees(N);
    for(int i = 0; i < N; ++i) {
      cin>>trees[i].first>>trees[i].second;
    }
    ll ans = 0;
    sort(trees.begin(), trees.end());
    for(int i = 0; i < N; ++i) {
      auto P = trees[i].first, H = trees[i].second;
      dp[P + H] = max(dp[P + H], H + dp[P]);
      dp[P] = max(dp[P], H + dp[P - H]);
      ans = max(ans, max(dp[P+H], dp[P]));
    }
    cout<<"Case #"<<CASE++<<":"<<endl;
    cout<<ans<<endl;
  }
  return 0;
}


