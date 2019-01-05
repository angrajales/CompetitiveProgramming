#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int dp[s.size() + 1];
  memset(dp, 0, sizeof dp);
  int res = -1;
  for(int i = 0; i < s.size(); ++i){
    dp[i] = 1;
    for(int j = i + 1; j < s.size(); ++j){
      if(s[j] > s[i]){
        //cerr << s[j] << " " << s[i] << endl;
        dp[j] = max(dp[i] + 1, dp[j]);
      }
    }
  }
  for(int j = 0; j < s.size(); ++j){
    cerr << dp[j] << endl;
    res = max(res, dp[j]);
  }
  cout << 26 - res << endl;
  return 0;
}