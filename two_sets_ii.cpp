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

const ll M = 1e9 + 7;
ll ans = 0;
ll res = 0;
int main() {
  IOS
  ll n; cin>>n;
  ll s = (n * (n + 1)) / 2;
  if(s & 1) {
    cout<<0;
    return 0;
  }
  ll dp[s + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for(ll i = 1; i <= n; ++i) {
    for(ll j = (i * (i + 1))/2; j >= i; --j) {
      (dp[j] += dp[j - i]) %= M;
    }
  }
  cout<<(dp[s/2] * (M+1)/2) % M<<endl;
  return 0;
}


