#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;
vector<int> v;

int main(){
  int i = 0;
  int n;
  mp.clear();
  while(cin >> n){
    if(mp[n] == 0){
      v.push_back(n);
    }
    mp[n]++;
  }
  for(int i = 0; i < v.size(); ++i){
    cout << v[i] << " "<< mp[v[i]] << endl;
  }
  return 0;
}