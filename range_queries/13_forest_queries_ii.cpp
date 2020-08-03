#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, order_statistics_node_update>;
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

const ll maxn = 1e3 + 1;
ll arr[maxn];
struct ST{
  ll mx, mxl, mxr, s;
} st[(ll)1e6];
ll n, m, q;
struct BIT{
  vector<ll> arr;
  BIT(){arr.resize(maxn + 1);}
  void update(ll x, ll num) {
    while(x <= n) {
      arr[x] += num;
      x += x & -x;
    }
  }

  ll query(ll x) {
    ll sum = 0;
    while(x > 0) {
      sum += arr[x];
      x -= x & -x;
    }
    return sum;
  }
} bits[maxn];

ll ft[maxn][maxn];
void update(ll x, ll y, ll v) {
  for(int i = x; i <= n; i += i & (-i)) {
    // for(int j = y; j <= n; j += j & (-j)) ft[i][j] += v;
    bits[i].update(y, v);
  }
}
ll query(ll x, ll y) {
  // if(x == 0 || y == 0) return 0;
  ll res = 0;
  for(int i = x; i > 0; i -= i & -i) {
    // for(int j = y; j > 0; j -= j & -j) res += ft[i][j];
    res += bits[i].query(y);
  }
  return res;
}
int main() {
  IOS
  cin>>n>>q;
  string g[n];
  
  for(int i = 0; i < n; ++i) {
    cin>>g[i];
    for(int j = 0; j < g[i].size(); ++j) {
      if(g[i][j] == '*')
        update(i + 1, j + 1, 1);
    }
  }
  
  while(q--) {
    ll i, x, y, x2, y2; cin>>i>>x>>y;
    if(i == 1) {
      update(x, y, g[x - 1][y - 1] == '*' ? -1 : 1);
      g[x - 1][y - 1] = g[x - 1][y - 1] == '*' ? '.': '*';
    }else{
      cin>>x2>>y2;
      ll res = query(x2, y2) - query(x-1, y2) -  query(x2, y - 1) + query(x - 1, y - 1);
      cout<<res<<endl;
    }
  }
  return 0;
}
