#include <bits/stdc++.h>

using namespace std;

int main(){
  int clues;
  cin >> clues;
  int sol = 0, sum = 0;
  for(int i = 1; i < 100; ++i){
    sum += (i * (i + 1) / 2);
    if(sum > clues) break;
    sol++;  
  }
  cout << sol << endl;
}