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

ll adj[51][51];
int main() {
  IOS
  ll T; cin>>T;
  ll CASE = 1;
  while(T--) {
    ll N; cin>>N;
    vs arr(2);
    for(int i = 0; i < 2; ++i) cin>>arr[i];
    memset(adj, 0, sizeof(adj));
    for(int i  = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        if(abs(i - j) <= 1){
          adj[i][j] = 1;
        }
      }
    }
    for(int i  = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        if(i == j) continue;
        if(arr[0][i] == 'Y')
          adj[j][i] &= 1;
        if(arr[1][i] == 'Y')
          adj[i][j] &= 1;
      }
    }
    for(int i  = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        if(i == j) continue;
        if(arr[0][i] == 'N')
          adj[j][i] = 0;
        if(arr[1][i] == 'N')
          adj[i][j] = 0;
      }
    }
    for(int k = 0; k < N; ++k) {
      for(int i  = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
          adj[i][j] |= adj[i][k] && adj[k][j];
        }
      }
    }
    cout<<"Case #"<<CASE++<<":"<<endl;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        if(adj[i][j])
          cout<<"Y";
        else
          cout<<"N";
      }
      cout<<endl;
    }
    
  }
  return 0;
}


