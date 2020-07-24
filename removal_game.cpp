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

pair<ll, ll> dp[5000][5000];
ll ans = 0;
ll res = 0;
int main() {
  IOS
  ll n; cin>>n;
  vi arr;
  filli(n, arr);
  for(int i = n - 1; i >= 0; --i) {
    dp[i][i] = {arr[i], 0};
    for(int j = i + 1; j < n; ++j) {
      if(dp[i + 1][j].second + arr[i] > dp[i][j - 1].second+ arr[j]) {
        dp[i][j] = {dp[i + 1][j].second + arr[i], dp[i + 1][j].first};
      }else{
        dp[i][j] = {dp[i][j - 1].second + arr[j], dp[i][j - 1].first};
      }
    }
  }
  cout<<dp[0][n-1].first<<endl;
  return 0;
}


