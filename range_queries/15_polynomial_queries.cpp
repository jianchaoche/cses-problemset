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

const ll maxn = 2e5 + 1;
ll arr[maxn];
struct ST{
  ll s, lz, lz2 = 0;
} st[(ll)1e6];
ll n, m, q;

void app(ll i, ll x, ll x2, ll l, ll r) {
  st[i].s += (r - l + 1) * x + x2 * ((r + 1) * r / 2 - (l - 1) * l / 2);
  st[i].lz += x;
  st[i].lz2 += x2;
}
void psh(ll i, ll l, ll mid, ll r) {
  app(2 * i, st[i].lz, st[i].lz2, l, mid);           //----------------
  app(2 * i + 1, st[i].lz, st[i].lz2, mid + 1, r);  //---------------------------
  st[i].lz = 0;
  st[i].lz2 = 0;
  st[i].s = st[i * 2].s + st[i * 2 + 1].s;
}

void upd(ll l1, ll x, ll i = 1, ll l2 = 0, ll r2 = n - 1) {
  if(l2 == r2) {
    st[i].s = x; return;
  }
  ll mid = (l2 + r2) / 2;
  // psh(i, l2, mid, r2);
  if(l1 <= mid)
    upd(l1, x, i * 2, l2, mid);
  else
  {
    upd(l1, x, i * 2 + 1, mid + 1, r2);
  }
  st[i].s = st[i *  2].s + st[i * 2+ 1].s;
}
void update(ll l1, ll r1, ll x, ll x2, ll i = 1, ll l2=0, ll r2=n - 1) {
  if(l1 <= l2 && r1 >= r2) {
    app(i, x, x2, l2, r2); 
    return;
  }
  ll mid = (l2 + r2) / 2;
  psh(i, l2, mid, r2); 
  if(l1 <= mid) 
    update(l1, r1, x, x2, i * 2, l2, mid);
  if(mid < r1)//------------------------------------------------------------------
    update(l1, r1, x, x2, i * 2 + 1, mid + 1, r2);
  st[i].s = st[2 * i].s + st[2 * i + 1].s;
}

ll query(ll l1, ll r1, ll i = 1, ll l2 = 0, ll r2 = n - 1) {
  if(l1 <= l2 && r1 >= r2) 
    return st[i].s;
  if(l1 > r2 || l2 > r1) return 0;
  ll mid = (l2 + r2) / 2;
  psh(i, l2, mid, r2);//-------------------------------------------
  return query(l1, r1, i * 2, l2, mid) + query(l1, r1, i * 2 + 1, mid + 1, r2);
}

int main() {
  IOS
  cin>>n>>q;
  for(int i = 0; i < n; ++i) {
    cin>>arr[i];
    upd(i, arr[i]);
  }
  ll qt;
  while(q--) {
    ll a, b, c;
    cin>>qt>>a>>b; --a; --b;
    if(qt == 1) {
      update(a, b, 1 - a, 1);
    }else if(qt == 2) {
      cout<<query(a, b)<<endl;
    }
  }
  return 0;
}
