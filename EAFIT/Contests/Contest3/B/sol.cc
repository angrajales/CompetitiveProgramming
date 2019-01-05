#include <bits/stdc++.h>

using namespace std;

int a[5];

bool solve(int res, int index){
  if(index == 5){
    return 23 == res;
  }
  bool can = solve(res - a[index], index + 1);
  can |= solve(res * a[index], index + 1);
  can |= solve(res + a[index], index + 1);
  return can;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(true){
    bool finish = true;
    for(int i = 0; i < 5; ++i){
      cin >> a[i];
      finish &= !a[i];
    }
    if(finish) break;
    bool can = false;
    sort(a, a+5);
    do{
      if(solve(a[0], 1)){ 
        can = true;
        break;
      }
    }while(next_permutation(a, a + 5));
    if(can){
      cout << "Possible" << endl;
    }else{
      cout << "Impossible" << endl;
    }
  }
}