#include <bits/stdc++.h>

using namespace std;

int a[120001];
map<int, int> mp;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    mp[a[i]]++;
  }
  int res = n;
  for(int i = 0; i < n; ++i){
    for(int k = 0; k <= 30; ++k){
      int p = 1<<k;
      if(p-a[i]==a[i] && mp[a[i]] < 2) continue;
      if(mp[p-a[i]]){
        res--;
        break;
      }
    }
  }
  cout << res << endl;
}