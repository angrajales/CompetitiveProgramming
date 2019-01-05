#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while(n--){
    string next;
    cin >> next;
    if(mp[next] == 0){
      mp[next] ++;
      cout << "OK" << endl;
    }else{
      cout << next << mp[next] << endl;
      mp[next]++;
    }


  }
  return 0;
}