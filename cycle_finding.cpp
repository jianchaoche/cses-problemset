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

bool vis[10001];
ll pu[10001];

int main() {
  IOS
  ll n,m; cin>>n>>m;
  vvi edges;
  for(int i = 0; i < m;++i) {
    ll a, b, c; cin>>a >>b>>c;
    edges.push_back({a, b, c});
  }
  vi dp(n+ 1);
  for(int i = 0; i <= n; ++i) {
      for(auto &e : edges) {
        ll j = e[0];
        ll x = e[1];
        ll u = j, v = x;
        ll dist = e[2] + dp[u];
        if (dist < dp[v]) {
          dp[v] = dist;
          pu[v] = u;
          if(i == n) {
            while(!vis[j]){
              vis[j] = 1;
              j = pu[j];
            }
            u = j;
            cout<<"YES"<<endl;
            vi ans;
            ans.push_back(u);
            u = pu[u];
            while(u != j ) {
              ans.push_back(u);
              u = pu[u];
            }
            ans.push_back(u);
            reverse(ans.begin(), ans.end());
            for(auto x : ans) cout<<x<<" ";
            return 0;
          }
        
        }
    }
  }
  cout<<"NO";
  return 0;
}


