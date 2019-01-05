#include <bits/stdc++.h>

using namespace std;

int ds(long long int n){
  int res = 0;
  while(n > 9){
    res += n % 10;
    n = n / 10;
  }
  res += n;
}

int main(){
  long long int n;
  cin >> n;
  long long int new_n = 0;
  int sum = 0, res = 0;
  for(int i = 1; i <= 9; ++i){
    if(i <= n){
      new_n = i;
      while(new_n <= n){
        sum = ds(new_n);
        new_n = new_n * 10 + 9; 
      }
      res = max(res, sum);
     }
  }
  cout << res << endl;
  return 0;
}