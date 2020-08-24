#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
//#define F0R(i,a) FOR(i,0,a)
#define INF = 1e18;
#define REP(i, m) for(ll i = 0; i < (m); ++i)
#define acc(arr) accumulate(arr.begin(), arr.end(), 0)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI=acos(-1.0);
const double epsilon=PI/180.0;
typedef vector<string> vs;
typedef long long ll;typedef unsigned int unit32;typedef unsigned long long ull;typedef vector<ll> vi;typedef vector<vector<ll> > vvi;typedef map<ll, ll> mii;typedef map<string, string> mss;typedef map<ll, string> mis;typedef map<string, ll> msi;typedef pair<ll, ll> pii;
 
 vector<ll> lps(string &s) {
   vector<ll> arr(s.size());
   ll j = 0;
   for(int i = 1; i < s.size(); ++i) {
     while(j > 0 && s[i] != s[j]) j = arr[j - 1];
     if(s[i] == s[j]) arr[i] = ++j;
     
   }
   return arr;
 }
int main() {
  IOS
  string n, m;
  cin>>n>>m;
  // if(m.size() > n.size()) {cout<<"0"<<endl; return 0;}
  auto arr = lps(m);
  for(int i = 0; i < n.size(); ++i) {
    
  }
  return 0;
}