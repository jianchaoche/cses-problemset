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

const ll MAXN=1e5 + 1, M = 1e9 + 7;
ll dp[MAXN][101];
int main() {
  IOS
  ll n, m; cin>>n>>m;
  vi arr(n);
  for(ll i = 0; i < n; ++i) {
    cin>>arr[i]; --arr[i];
  }
  for(ll i = 0; i < arr.size(); ++i){
    for(int j = 0; j < m ;++j) {
      if(i) {
        dp[i][j] += dp[i-1][j];
        if(j) dp[i][j] += dp[i-1][j - 1];
        if(j < m - 1) dp[i][j] += dp[i-1][j + 1];
        dp[i][j] %= M;
      }else 
        dp[i][j] = 1;
    }
    if(arr[i] >= 0) {
      for(ll j = 0; j < m; ++j) {
        if(j != arr[i])
          dp[i][j] = 0;
      }
    }
  }
  ll ans = 0;
  for(int i = 0; i < m; ++i)
    ans += dp[n-1][i];
  ans %= M;
  cout<<ans<<endl;
  return 0;
}


