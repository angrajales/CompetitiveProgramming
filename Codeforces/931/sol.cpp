#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  a--, b--;
  int round = 1;
  while(n > 2){
    if(a / 2 == b / 2){
      cout << round << endl;
      return 0;
    }
    a /= 2;
    b /= 2;
    round++;
    n = n / 2;
  }
  cout << "Final!" << endl;
  return 0;
}

