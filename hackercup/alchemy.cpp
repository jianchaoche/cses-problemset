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

const ll maxn = 1e5;
bool dp[maxn][3][3];
ll dfs(string &s, int left, int A, int B) {
  if(left == s.size()) return true;
  
  if(s.size() - left == 3) {
    return !(s[left] == s[left + 1] && s[left] == s[left + 2]);
  }
  
  int a = dfs(s, left + 1, A + 1, B);
  dfs(s, left + 1, A, B, )
  if ((s[left] == 'A') + A < 3)
    dfs(s, left + 1, A + (s[left] == 'A'), B + (s[left] == 'B'));
  dfs(s, left + 2, A + (s[left] == 'A') + (s[left + 1] == 'A'), B + (s[left] == 'B') + (s[left + 1] == 'B'));
  !(s[left] == s[left + 1] && s[left] == s[left + 2]) && dfs(s, left + 3, 0, 0);
}

int main() {
  IOS
  ll T; cin>>T;
  ll CASE = 1;
  while(T--) {
    ll N; cin>>N; string s; cin>>s;

    return 0;
  }
}


