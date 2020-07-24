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

/*
  
5 8
########
#..#...#
####.#.#
#..#...#
########
*/

void dfs(vector<string> &arr, int x, int y) {
  if(x < 0 || y < 0 || x >= arr.size() || y >= arr[0].size() || arr[x][y] == '#') return;
  arr[x][y] = '#';
  dfs(arr, x + 1, y);
  dfs(arr, x - 1, y);
  dfs(arr, x, y + 1);
  dfs(arr, x, y - 1);
}

int main() {
  IOS
  ll m, n; cin>>m>>n;
  vector<string> arr(m);
  for(ll i = 0; i < m; ++i) 
    cin>>arr[i];
  ll ans = 0;
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      if(arr[i][j ] == '.') {
        dfs(arr, i, j);
        ++ans;
      }
    }
  }
  cout<<ans;
  return 0;
}

