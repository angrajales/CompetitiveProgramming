#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int like[N + 1][N + 1];
long long dp[(1 << N) + 2];
int n;

long long solve(int mask){
  int idx = __builtin_popcount(mask);
  if(idx == n){
    return 1;
  }
  if(dp[mask] != -1){
    return dp[mask];
  }
  long long res = 0;
  for(int i = 0; i < n; ++i){
    if(like[idx][i] && (mask & (1 << i)) == 0){
      res += solve(mask | (1 << i));
    }
  }
  dp[mask] = res;
  return res; 
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        cin >> like[i][j];
      }
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0) << endl;
  }
  return 0;
}