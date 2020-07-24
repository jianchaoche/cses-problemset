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

ll M = 1e9 + 7;
ll dp[1000005];

ll dfs(int n) {
  if(n < 0) return 0;
  if(n == 0) return 1;
  if(n == 1) return 1;
  if(dp[n]) return dp[n];
  ll res = 0;
  for(int i = 1; i <= 6; ++i) {
    res += dfs(n - i);
    res %= M;
  }
  return dp[n] = res;
}
int main() {
  IOS
  ll n; cin>>n;
  dp[0] = 1;
  for(ll i = 1; i <= n; ++i) {
    for(ll j = 6; j>= 1; --j) {
      if(i - j >= 0)
        dp[i] += dp[i - j];
      dp[i] %= M;
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}


