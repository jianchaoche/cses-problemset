
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn = 1e6 + 1;
bool dp[maxn];

int main(){
  vector<ll> arr(100);
  ll t; cin>>t;
  while(t--){
    ll n; cin>>n;
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
      ll a; cin>>a;
      ans ^= a;
    }
    cout<<(ans ? "first":"second")<<endl;
  }
  return 0;
}