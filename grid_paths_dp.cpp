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

const ll M = 1e9 + 7, MAXN = 1e6 + 1;
ll arr[100];
ll dp[1000][1000];
int main() {
  IOS
  ll n; cin>>n;
  vs arr(n);
  for(int i = 0; i < n; ++i)
    cin>>arr[i];
  if(arr[0][0] == '*') {
    cout<<0; return 0;
  }
  dp[0][0] = 1;
  for(int i = 1; i < n; ++i) {
    if(arr[i][0] == '*' ) dp[i][0] = 0;
    else dp[i][0] = dp[i-1][0];
    if(arr[0][i] == '*') dp[0][i] = 0;
    else dp[0][i] = dp[0][i-1];
  }
  for(int i = 1; i < n; ++i) {
    for(int j = 1; j < n; ++j) {
      if(arr[i][j] == '*') {
        dp[i][j] = 0;continue;
      }
      dp[i][j] = dp[i-1][j] + dp[i][j-1];
      dp[i][j] %= M;
    }
  }
  cout<<dp[n-1][n -1 ];
  return 0;
}


