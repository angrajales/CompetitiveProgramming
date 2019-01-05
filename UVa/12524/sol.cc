#include <bits/stdc++.h>

using namespace std;

int cost[1001][2];

const int inf = 1 << 30;

int dp[1001][1001][1001];

int solve(int i, int j, int k){
  if(i > j || j == 0){
    return inf;
  }
  if(i < 0 | j < 0 | k < 0) return inf;
  if(k == 0){
    return 0;
  }
  int &ans = dp[i][j][k];
  if(ans != -1){
    return ans;
  }
  ans = min(ans, solve(j, j - 1, k - 1) + (cost[j][0] - cost[i][0]) * cost[i][1]);
  ans = min(ans, solve(i, j - 1, k));
  ans = min(ans, solve(i + 1, j, k - 1) +(cost[j][0]-cost[i][0]) * cost[i][1]);
  ans = min(ans, solve(i + 1, j, k));
  return ans;
}

int main(){
  int n, k; 
  while(cin >> n >> k){
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; ++i){
      cin >> cost[i][0] >> cost[i][1];
    }
    cout << solve(0, n - 1, k) << endl;

  }
  return 0;
}