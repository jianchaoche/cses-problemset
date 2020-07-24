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
#.A#...#
#.##.#B#
#......#
########
*/


int main() {
  IOS
  ll m, n; cin>>m>>n;
  vector<string> arr(m);
  pair<ll, ll> A, B;
  for(ll i = 0; i < m; ++i) {
    cin>>arr[i];
    ll j = arr[i].find('A');
    if(j >= 0) {
      A = {i, j};
      arr[i][j] = '#';
    }
    j = arr[i].find('B');
    if(j >= 0) {
      B = {i, j};
    }
  }
  pair<ll, ll> path[m][n];
  queue<pair<ll, ll> > q;
  q.push(A);
  ll d[5] = {0, 1, 0, -1, 0};
  bool res = false;
  while(q.size()) {
    auto p = q.front();q.pop();
    if(p == B) {
      res = true;
      break;
    }
    for(int i = 0; i < 4; ++i) {
      int nx = p.first + d[i];
      int ny = p.second + d[i + 1];
      if(nx < 0 || ny < 0 || nx >= m || ny >= n || arr[nx][ny] == '#') continue;
      path[nx][ny] = p;
      q.push({nx, ny});
      arr[nx][ny] = '#';
    }
  }
  if(!res) {cout<<"NO"; return 0;};
  
  auto p = B;
  string ans;
  while(p != A) {
    auto prev = path[p.first][p.second];
    if(p.first - prev.first) {
      ans.push_back(p.first - prev.first > 0 ? 'D' : 'U');
    }else {
      ans.push_back(p.second - prev.second > 0 ? 'R' : 'L');
    }
    p = prev;
  }
  cout<<"YES"<<endl<<ans.size()<<endl;;
  reverse(ans.begin(), ans.end());
  cout<<ans;
  return 0;
}

