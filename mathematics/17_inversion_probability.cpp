
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll n; cin>>n;
  vector<ll> arr(101);
  double ans = 0;
  for(int i = 0; i < n; ++i) {
    cin>>arr[i];
    ll cnt = 0;
    for(int j = 0; j < i; ++j) {
      cnt = min(arr[i], arr[j]) * (min(arr[i], arr[j]) - 1) / 2;
      if(arr[j] > arr[i]) {
        cnt += (arr[j] - arr[i]) * arr[i];
      }
      ans += double(cnt)/ (arr[j] * arr[i]);
    }
  }
  cout<<fixed<<setprecision(6)<<ans<<endl;
  return 0;
}