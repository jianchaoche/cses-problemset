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
  ll n; cin>>n;
  set<vi> m;
  vector<vector<ll> > arr;
  ll idx1 = 0;
  while(n--) {
    ll a,b; cin>>a>>b;
    arr.push_back({b, a, idx1++});
  }
  sort(arr.begin(), arr.end());
  vi ans(arr.size());
  ll cnt = 0, mx = 0;
  for(ll i = 0; i < arr.size(); ++i) {
    ll b = arr[i][0], a = arr[i][1], idx = arr[i][2];
    auto it = m.lower_bound({ a });
    if (it != m.begin()) {
      --it;
      ans[idx] = ((*it)[1]);
      m.erase(it);
    }else {
      ans[idx] = m.size();
    }
    m.insert( { b, ans[idx] } );
  }
  cout<<m.size()<<endl;
  for(auto num : ans)
    cout<<num + 1<<" ";
  return 0;
}


