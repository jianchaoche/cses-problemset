#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7, maxn= 1e6 + 1;
ll inv[maxn + 1];
ll f[maxn + 1], f2[maxn + 1];
int main() {
  string s; cin>>s;

  inv[1] = 1;
  inv[0] = 1;
  f[0] = 1;
  f2[0] = 1;
  ll p = M;
  for (int i = 2; i <= maxn; i++) {
    inv[i] = ((p - p / i) * inv[p % i]) % p;
  }
  for(ll i = 1; i <= maxn; ++i) {
    f[i] = (i * f[i - 1]) % M;
    f2[i] = (f2[i - 1] * inv[i]) % M;
  }
  ll cnt[26];memset(cnt, 0, sizeof(cnt));
  for(char c : s) {
    ++cnt[c - 'a'];
  }
  ll ans = f[s.size()];
  for(auto n : cnt) {
    ans = (ans * f2[n]) % M;
  }
  cout<<ans<<endl;
  return 0;
}
