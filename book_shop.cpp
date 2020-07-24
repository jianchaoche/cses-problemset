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

const ll MAXN = 1e5 + 10, N = 1000;
ll dp[MAXN];
int main() {
  IOS
  ll n, x; cin>>n>>x;
  vi prices(n), pages(n);
  for(int i = 0; i < n; ++i) {
    cin>>prices[i];
  }
  for(int i = 0; i < n; ++i) {
    cin>>pages[i];
  }
  // memset(dp, -1, sizeof(dp));
  // dp[0] = 0;
  for(ll i = 0; i < prices.size(); ++i) {
    ll p = prices[i];
    for(ll j = x; j>= prices[i]; --j) {
      if(dp[j - p] >= 0) {
        dp[j] = max(dp[j], dp[j - p] + pages[i]);
      }
    }
  }
  cout<<(dp[x] == -1 ? 0 : dp[x])<<endl;
  return 0;
}


