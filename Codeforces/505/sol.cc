#include <bits/stdc++.h>

using namespace std;

int a[30001];
int p[30001];
int dp[30001][501];

int solve(int i, int prev, int &d){
  int calc = prev - (d - 250);
  if(i > 30000){
    return 0;
  }
  if(dp[i][calc] != -1) return dp[i][calc];
  int res = 0;
  if(prev == 1){
    res = solve(i + prev + 1, prev + 1, d);
    //res = max(res, solve(i + prev - 1, prev - 1, d)) + p[i];
    res = max(res, solve(i + prev, prev, d));
    res = res + p[i];
  }else{
    res = solve(i + prev + 1, prev + 1, d);
    res = max(res, solve(i + prev - 1, prev - 1, d));
    res = max(res, solve(i + prev, prev, d));
    res = res + p[i];
  }
  dp[i][calc] = res; 
  return res; 
}



int main(){
  int n, d;
  cin >> n >> d;
  memset(dp, -1, sizeof dp);
  memset(p, 0, sizeof p);
  for(int i = 0; i < n; ++i) {
    cin >> a[i]; 
    p[a[i]] += 1;
  }
  int res = solve(d, d, d);
  cout << res << endl;
  return 0;
}