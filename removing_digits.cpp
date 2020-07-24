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

const int MAXN = 1e6+1;
int v[MAXN];

int main() {
  IOS
  ll n; cin>>n;
  queue<ll> q;q.push(n);
  v[n] = 1;
  ll step = 0;
  while(q.size()) {
    ll size = q.size();
    while(size--) {
      ll num = q.front(); q.pop();
      ll t = num;
      while(t > 0) {
        ll n = num - (t % 10);
        t /= 10;
        if(n == 0) {
          cout<<step + 1<<endl;
          return 0;
        }
        if(!v[n]) {
          v[n] = 1;
          q.push(n);
        }
      }
    }
    ++step;
  }
  return 0;
}


