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

const ll maxn = 2e6 + 1;
vvi adj(maxn);
vi vis(maxn);
vi ans;
int main() {
  IOS
  ll n; cin>>n;
  ll m = 1 << n;
  string ans = string(n, '0');
  vis[0] = 0;
  for(int i = 1; i < m;++i) {
    ll cnt = n - 1;
    ll num = 0;
    while(cnt > 0) {
      ll c = ans[ans.size() - cnt] - '0';
      num = (num << 1) + c;
      --cnt;
    }
    if(!vis[(num << 1 ) + 1]) {
      ans += '1';
      vis[(num << 1 ) + 1] = 1;
    }else {
      ans += '0';
      vis[(num << 1 ) + 0] = 1;
    }
  }
  cout<<ans;
  return 0;
}


