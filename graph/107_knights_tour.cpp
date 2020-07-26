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

const ll maxn = 2e5 + 1;
vvi adj(maxn);
ll vis[8][8];
vi path(maxn);
vi eu(maxn), ev(maxn);
vi ans;
ll n, m,f = 0;
vi in(maxn), out(maxn);
vector<pair<int, int> > p(8);

bool isFree(int nx, int ny) {
  return !(nx< 0 || ny < 0 || nx >= 8 || ny >=8 || vis[nx][ny]);
}

int deg(int x, int y) {
  int d = 0;
  for(int i = 0; i < 8; ++i) {
    int nx = x + p[i].first, ny = y + p[i].second;
    d += isFree(nx, ny);
  }
  return d;
}

bool dfs(ll x, ll y, ll step) {
  if(vis[x][y]) return false;
  vis[x][y] = step;
  if(step == 64) return true;
  vector<vector<int> > vec;
  for(int i = 0; i < 8; ++i) {
    int nx = x + p[i].first, ny = y + p[i].second;
    if(isFree(nx, ny)) {
      vec.push_back({ deg(nx, ny), nx, ny });
    }
  }
  sort(vec.begin(), vec.end());
  // reverse(vec.begin(), vec.end());
  for(auto &v : vec) {
    if(dfs(v[1], v[2], step + 1)) return true;
  }
  vis[x][y] = 0;
  return false;
}
int main() {
  IOS
  int dx[8] = {1,1, 2, 2, -1, -1,-2, -2 };
  int dy[8] = {2,-2, 1,-1, 2, -2, 1, -1 };
  for(int i = 0; i < 8; ++i) {
    p[i] = {dx[i], dy[i]};
  }
  ll x, y;
  cin>>y>>x;
  dfs(x-1, y-1, 1);
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j) {
      cout<<vis[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
