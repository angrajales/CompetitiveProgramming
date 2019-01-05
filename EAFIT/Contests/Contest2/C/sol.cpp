#include <bits/stdc++.h>

using namespace std;

bool a[10002][501];
vector<vector<int>> nn;
map<vector<int>, int> mp;

int main( ){
  ios_base::sync_with_stdio( false );
  cin.tie( NULL );
  cout.precision( 11 );
  cout << fixed;
  int n;
  memset(a, 0, sizeof a);
  while(cin >> n){
    if(n == 0) break;
    mp.clear();
    for(int i = 0; i < n; ++i){
      vector<int> v(5);
      for(int j = 0; j < 5; ++j){
        cin >> v[j];
      }
      sort(v.begin(), v.end());
      nn.push_back(v);
      mp[v]++;
    }
    int maximun = 0, res = 0;
    vector<int> n_k;
    for(map<vector<int>, int>::iterator it = mp.begin(); it != mp.end(); ++it){
      if(it->second == maximun){
        res += it->second;
      }else if(it->second > maximun){
        maximun = it->second;
        res = it->second;
      }
    }
    
    cout << res << endl;   
  }
  return 0;
}