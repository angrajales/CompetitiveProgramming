#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int n, m;
  cin >> n;
  m = n;
  int cnt = 0;
  while(n > 0){
    if(!(n & 1LL)){
      cnt++;
    }
    n >>= 1LL;
  } 
  cout << (1LL << cnt) << endl;
  return 0;
}