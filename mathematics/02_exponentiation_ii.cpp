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

const ll maxn = 2e5 + 1, M = 1e9 + 7;
ll arr[maxn];
ll n, m, q;


ll exp(ll a, ll b, map<ll, ll> &dp, ll M) {
  if(b == 0) return 1;
  if(a == 0) return 0;
  if(b == 1) return a;
  if(dp.count(b)) return dp[b];
  ll res = ((exp(a, b / 2, dp, M) % M) * (exp(a, b/ 2, dp, M) % M)) %M;
  res = (res * (b % 2 ? a :  1)) % M;
  return dp[b] = res;
}

int main() {
  IOS
  cin>>n;
  q = n;
  while(q--) {
    map<ll, ll> dp;
    map<ll, ll> dp2;
    ll a, b, c; cin>>a>>b>>c;
    b = exp(b, c, dp2, M - 1);
    cout<<exp(a, b, dp, M)<<endl;
  }
  return 0;
}
