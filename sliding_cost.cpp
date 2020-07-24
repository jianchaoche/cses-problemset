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
  vi arr;
  filli(n, arr);
  multiset<ll> ts, bs;
  ll tsum = 0, bsum = 0;
  for(ll i = 0; i < arr.size(); ++i) {
    if(i - k >= 0) {
      if(ts.find(arr[i-k]) != ts.end()){
        tsum -= arr[i-k];
        ts.erase(ts.find(arr[i-k]));
      }
      else{
        bsum -= arr[i-k];
        bs.erase(bs.find(arr[i-k]));
      }
    }
    if(ts.size() > bs.size()) {
      bs.insert(arr[i]);
      bsum += arr[i];
    }else{
      tsum += arr[i];
      ts.insert(arr[i]);
    }
    if(bs.size()) {
      auto tv = ts.end();
      --tv;
      bs.insert(*tv);
      tsum -= *tv;
      bsum += *tv;
      ts.erase(tv);
      
      auto bv = bs.begin();
      tsum += *bv;
      bsum -= *bv;
      ts.insert(*bv);
      bs.erase(bv);
    }
    if(i < k - 1) continue;
    ll md = 0;
    if((ts.size() + bs.size()) % 2)
      md = *ts.rbegin();
    else
    {
      md = min(*ts.rbegin(), *bs.begin());
    }
    cout<<(ts.size() * md - tsum + bsum - bs.size() * md)<<" ";
  }
  return 0;
}


