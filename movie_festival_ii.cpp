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
  ll n, k; cin>>n>>k;
  vvi arr;
  while(n--) {
    ll a,b; cin>>a>>b;
    arr.push_back({b, a});
  }
  sort(arr.begin(), arr.end());
  ll ans = 0;
  multiset<ll> s;
  for(int i = 0; i < arr.size(); ++i) {
    auto it = s.lower_bound(arr[i][1] + 1);
    if(it != s.begin()) {
      --it;
      s.erase(it);
    }
    if(s.size() < k) {
      s.insert(arr[i][0]);
      ++ans;
    }
  }
  cout<<ans<<endl;
  return 0;
}


