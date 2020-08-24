#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;
ll c(ll n) {
  ll p = ((n % M) * ((n + 1) % M)) % M;
  ll a = ((M + 1) / 2) % M;
  return (p * a) % M;
}
int main() {
  ll n; cin>>n;
  ll ans = 0;
  
  for(ll i = 1; i <= n; i++) {
    ll r = n / (n / i);
    ans += ((n / i)% M) * ((c(r) - c(i - 1) + M) % M);
    ans %= M;
    i = r;
  }
  cout<<ans<<endl;
}
