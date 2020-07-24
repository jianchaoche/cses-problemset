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

void bfs(vs arr, queue<vi> &q, vvi &dis, vector<vector<pii> > &path, bool isA=false) {
  ll m = arr.size(), n = arr[0].size();
  int d[5] = {0, 1, 0, -1, 0};
  int step = 1;
  while(q.size()) {
    int size = q.size();
    while(size--) {
      auto p = q.front(); q.pop();
      for(int i = 0; i < 4; ++i) {
        int nx = p[0] + d[i];
        int ny = p[1] + d[i+1];
        if(nx < 0 || ny < 0 || nx >= m || ny >= n || dis[nx][ny] != 0 || arr[nx][ny] != '.') continue;
        
        path[nx][ny] = {p[0], p[1]};
        dis[nx][ny] = step + 1;
        // if(nx != 0 && ny != 0)
          q.push({nx, ny, p[2]});
        arr[nx][ny] = '#';
      }
    }
    ++step;
  }
}

int main() {
  IOS
  ll m, n; cin>>m>>n;
  vs arr(m);
  // vector<pii> monsters;
  vi me;
  queue<vi> q;
  vvi dis(m, vi(n)), dis2(m, vi(n));
  vector<vector<pii> > path(m, vector<pii>(n));
  vector<vector<pii> > path2(m, vector<pii>(n));
  for(int i = 0; i < arr.size(); ++i) {
    cin>>arr[i];
    for(int j = 0; j < arr[i].size(); ++j ){
      if(arr[i][j] == 'M'){
        // monsters.push_back({i, j});
        q.push({i, j, 0});
        dis[i][j] = 1;
      }
      if(arr[i][j] == 'A'){
        arr[i][j] = '.';
        dis2[i][j] = 1;
        me = {i, j, 1};
      }
    }
  }
  
  
  bfs(arr, q, dis, path);
  queue<vi> q2;
  q2.push(me);
  bfs(arr, q2, dis2, path2);
  pii last = {-1, -1};
  // for(auto x : dis) {
  //   for(auto y : x) {
  //     cout<<y<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;
  // for(auto x : dis2) {
  //   for(auto y : x) {
  //     cout<<y<<" ";
  //   }
  //   cout<<endl;
  // }
  // for(auto s : arr)
  //   cout<<s<<endl;
  ll mxd = INT_MAX;
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      if(i == 0 || j == 0 || i == m - 1|| j == n -1){
        if((dis[i][j] > dis2[i][j] || dis[i][j] == 0) && dis2[i][j] && mxd > dis2[i][j] ) {
          mxd = dis2[i][j];
          last = {i, j};
        }
      }
    }
  }
  // for(int i = 0; i < m; ++i) {
  //   if(dis[i][0] > dis2[i][0] && dis2[i][0] && mxd > dis2[i][0] ) {
  //     mxd = dis2[i][0];
  //     last = {i, 0};
  //   }
  //   if(dis[i].back() > dis2[i].back() && dis2[i].back() && mxd > dis2[i].back()) {
  //     mxd = dis2[i].back();
  //     last = {i, n - 1};
  //   }
  // }
  // for(int i = 0; i < n; ++i) {
  //   if(dis[0][i] > dis2[0][i] && dis2[0][i] > 0 && mxd > dis2[0][i]) {
  //     mxd = dis2[0][i];
  //     last = {0, i};
  //   }
  //   if(dis.back()[i] > dis2.back()[i] && dis2.back()[i] > 0 && mxd > dis2.back()[i]) {
  //     mxd = dis2.back()[i];
  //     last = {m - 1, i};
  //   }
  // }
  // cout<<last.first<<last.second<<" "<<mxd<<endl;
  if(last.first == -1) {
    cout<<"NO"; return 0;
  }
  cout<<"YES"<<endl;
  pii org = {me[0], me[1]};
  string ans;
  while(last != org) {
    auto next = path2[last.first][last.second];
    if(next.first != last.first) 
      ans.push_back(next.first > last.first ? 'U' : 'D');
    else if(next.second != last.second) 
      ans.push_back(next.second > last.second ? 'L' : 'R');
    last = next;
  }
  reverse(ans.begin(), ans.end());
  cout<<ans.size()<<endl;
  cout<<ans;
  return 0;
}

