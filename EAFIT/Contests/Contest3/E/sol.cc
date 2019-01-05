#include <bits/stdc++.h>

using namespace std;

const int N = 101;
const int inf = (int)1e9;

int a[N];

inline int solve(int days, int action){
  if(days < 1){
    return inf;
  }
  int res1 = inf * 2;
  int res2 = 
  switch(a[days]){
    case 0:
      res = min(res, solve(days - 1, 0));
      res = min(res, solve(days - 1, 1));
      res = min(res, solve(days - 1, 2)) + 1;
    case 1:
      res = min(res, solve(days - 1, 0));
      res = min(res, solve(days - 1, 1));
      res = min(res, solve(days - 1, 2)) + 1; 
    case 2:
    case 3:

  }

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  memset(dp, inf, sizeof dp);
  return 0;
}