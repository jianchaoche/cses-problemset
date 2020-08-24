
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn = 1e6 + 1;
bool dp[maxn];

int main(){
  vector<ll> arr(100);
  ll n, k; cin>>n>>k;
  
  for(int i = 0; i < k; ++i) {
    cin>>arr[i];
  }
  arr.resize(k);
  sort(arr.begin(), arr.end());
  for(auto x : arr) dp[x] = true;
  for(int i = 2; i <=n; ++i) {
    if(dp[i]) continue;
    for(int j = 0; j < arr.size() && arr[j] <= i; ++j ) {
      if(dp[i - arr[j]]) {
        continue;
      }
      dp[i] = true;
      break;
    }
  }
  for(int i = 1; i <= n; ++i)
    cout<<(dp[i] ? 'W' : 'L');
  return 0;
}