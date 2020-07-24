#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
//#define F0R(i,a) FOR(i,0,a)
#define INF = 1e18;
#define filli() ll n; cin>>n; ll t = n; vector<ll> arr; while(t--) {ll a; cin>>a; arr.push_back(a);}
#define fills(arr) string a; cin>>a; arr.push_back(a);
#define REP(i, m) for(ll i = 0; i < (m); ++i)
#define acc(arr) accumulate(arr.begin(), arr.end(), 0)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI=acos(-1.0);
const double epsilon=PI/180.0;
typedef vector<string> vs;
typedef long long ll;typedef unsigned int unit32;typedef unsigned long long ull;typedef vector<ll> vi;typedef vector<vector<ll> > vvi;typedef map<ll, ll> mii;typedef map<string, string> mss;typedef map<ll, string> mis;typedef map<string, ll> msi;typedef pair<ll, ll> pii;

int grid[7][7];

int ans = 0;
bool h(int i, int j) {
  return i >= 0 && j>= 0 && i < 7 && j < 7 && !grid[i][j];
}
bool dfs(int x, int y, string &s, int idx) {
  if(idx == s.size()) {
    if(x == 6 && y == 0)
      ++ans;
    return true;
  }
  if(x < 0 || y < 0 || x >= 7 || y >= 7 || grid[x][y] == 1) return false;
  if(x == 6 && y == 0) return false;
  grid[x][y] = 1;
  char c = s[idx];
  if(c == 'D' || c == '?')
    if(x < 6 && !grid[x + 1][y] )
      if(!(!h(x + 2, y) && h(x + 1, y + 1) && h(x + 1, y - 1)))
        dfs(x + 1, y, s, idx + 1);
  if(c == 'U' || c == '?')
    if(x > 0 && !grid[x - 1][y] )
      if(!(!h(x - 2, y) && h(x - 1, y + 1) && h(x - 1, y - 1)))
        dfs(x - 1, y, s, idx + 1);
  if(c == 'L' || c == '?')
    if(y > 0 && !grid[x][y - 1])
      if(!(!h(x, y - 2) && h(x + 1, y - 1) && h(x - 1, y - 1)))
        dfs(x, y - 1, s, idx + 1);
  if(c == 'R' || c == '?')
    if(y < 6 && !grid[x][y + 1])
      if(!(!h(x, y + 2) && h(x + 1, y + 1) && h(x - 1, y + 1)))
        dfs(x, y + 1, s, idx + 1);
  grid[x][y] = 0;
  return true;
}
int main() {
  IOS
  string s; cin>>s;
  dfs(0, 0, s, 0);
  cout<<ans<<endl;
  return 0;
}


