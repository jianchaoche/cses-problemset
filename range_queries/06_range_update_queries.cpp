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

const ll maxn = 1<<20;
ll arr[maxn];
ll prefix[maxn];
ll n, m, q;
ll update(ll l1, ll x, ll i = 1, ll l2 = 0, ll r2 = n) {
  if (l2 == r2) {
    arr[i] += x;
    return arr[i];
  }
  ll mid = (l2 + r2) / 2;
  ll res;
  if(l1 <= mid) {
    res = update(l1, x, 2 * i , l2, mid);
  }else{
    res = update(l1, x, 2 * i + 1, mid + 1, r2);
  }
  arr[i] = arr[2 * i] + arr[2 * i + 1];
}

ll query(ll l1, ll r1, ll i = 1, ll l2 = 0, ll r2 = n) {
  if(l1 <= l2 && r1 >= r2) {
    return arr[i];
  }
  if(r1 < l2 || l1 > r2) return 0;
  ll mid = (l2 + r2) / 2;
  return query(l1, r1, i * 2, l2, mid) + query(l1, r1, i * 2 + 1, mid + 1, r2);
}

int main() {
  IOS
  cin>>n>>q;
  for(int i = 0; i < n; ++i) {
    ll x; cin>>prefix[i];
    // update(i, x);
  }
  while(q--) {
    ll o, a, b, u;cin>>o;
    if (o == 1) {
      cin>>a>>b>>u;
      update(a - 1, u);
      update(b, -u);
    }else{
      cin>>a;
      --a;
      cout<<(query(0, a) + prefix[a])<<endl;
    }
  }
  return 0;
}


/*
8 9
7 6 4 6 2 9 4 8
1 8 8 10
2 1
2 2
2 3
2 4
2 5
2 6
2 7
2 8
*/