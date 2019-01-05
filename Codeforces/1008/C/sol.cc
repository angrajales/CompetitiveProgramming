#include <bits/stdc++.h>

using namespace std;

int a[100005];
map<int, int> mp;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a, a + n);
  int res = 0;
  int diff = 0;
  for(int i = 1; i < n; ++i){
    if(a[i] == a[i - 1]) continue;
    if(mp[a[i]] > mp[a[i - 1]]){
      res += mp[a[i - 1]];
      mp[a[i]] -= mp[a[i - 1]];
      if(mp[a[i]] >= diff){
        res += diff;
        mp[a[i]]-=diff;
        diff = 0;
      }
      if(mp[a[i]] - diff < 0){
        res += mp[a[i]];
        diff -= mp[a[i]];
        mp[a[i]] = 0;
      }
    }
    if(mp[a[i]] < mp[a[i - 1]]){
      res += mp[a[i]];
      mp[a[i - 1]] -= mp[a[i]];
      if(diff - mp[a[i - 1]] < 0){
        res += diff;
        mp[a[i - 1]] -= diff;
        diff = 0;
      }
      if(diff - mp[a[i - 1]] >= 0){
        res += mp[a[i - 1]];
        diff -= mp[a[i - 1]];
        mp[a[i - 1]] = 0;
      }
      diff += (mp[a[i - 1]]);
    }
    if(mp[a[i]] == mp[a[i - 1]]){
      res += mp[a[i]];
      mp[a[i]] = 0;
    }
  }
  cout << res << endl;
  return 0;
}