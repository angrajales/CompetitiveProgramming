#include <bits/stdc++.h>

using namespace std;

int dp[52];

int main(){
  int n;
  while(cin >> n){
    if(n == 0) break;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i){
      dp[i] = dp[i - 1]+ dp[i - 2];
    }
    cout << dp[n] << endl;
  }
}