#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
int w[N], s[N];
int dp[N + 1];

int main(){
  int e1, e2;
  int cnt = 0;
  while(cin >> e1 >> e2){
    w[cnt] = e1;
    s[cnt++] = e2;
  }
  memset(dp, 0, sizeof dp);
  for(int i = 0; i < cnt; ++i){
    //int j_max = 0;
    for(int j = i + 1; j < cnt; ++j){
      if(w[j] > w[i] && s[i] > s[j]){
        dp[j] = max(dp[i] + 1, dp[j]);
      }
    }
    cerr << dp[i] << endl;
  }
  
  return 0;
}