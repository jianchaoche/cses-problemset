#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>
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

const ll maxn = 1<<21;
ll arr[maxn];
ll st[maxn];
ll n, m, q;

void update(ll l1, ll x, ll i = 1, ll l2 = 0, ll r2 = n) {
  if(l2 == r2) {
    st[i] += x; return;
  }
  ll mid = (l2 + r2) / 2;
  if(l1 <= mid) {
    update(l1, x, i * 2, l2, mid);
  }else
    update(l1, x, i * 2 + 1, mid + 1, r2);
  st[i] = st[i * 2] + st[i * 2 + 1];
}

ll query(ll l1, ll r1, ll i = 1, ll l2 = 0, ll r2 = n) {
  if(l1 <= l2 && r1 >= r2) {
    return st[i];
  }
  if( l1 > r2 || l2 > r1 ) return 0;
  ll mid = (l2 + r2) / 2;
  return query(l1, r1, i * 2, l2, mid) + query(l1, r1, i * 2 + 1, mid + 1, r2);
}

int main() {
  IOS
  cin>>n;
  for(int i = 1; i <= n; ++i) {
    cin>>arr[i - 1];
    update(i - 1, 1);
  }
  ll t = n;
  while(t--) {
    ll a; cin>>a;
    ll l = 0, r = n;
    while(l < r){
      
      ll mid = (l + r) / 2;
      ll cnt = query(0, mid);
      // cout<<mid<<" cnt:"<<cnt<<endl;
      if(cnt < a) {
        l = mid + 1;
      }else 
        r = mid;
      
    }
    if(l == n) cout<<0<<" ";
      else {
        cout<<arr[l]<<" ";
        update(l, -1);
      }
  }
  return 0;
}
