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

const ll maxn = 1e6 + 1, M = 1e9 + 7;
ll arr[maxn + 1];
vector<ll> prime;
ll n, m, q;

int main() {
  IOS
  cin>>n;
  q = n;
  for(int i = 2; i <= maxn; ++i) {
    if(!arr[i]) {
      arr[i] = i;
    }else {
      continue;
    }
    for(int j = i + i ; j <= maxn; j += i){
      arr[j] = i;
    }
  }
  while(q--) {
    ll a; cin>>a;
    map<ll, ll> m;
    ll j = 0;
    ll ans= 1;
    while(a > 1) {
      ++m[arr[a]];
      a /= arr[a];
    }
    for(auto it : m) {
      ans *= it.second + 1;
    }
    cout<<ans<<endl;
  }
  return 0;
}
