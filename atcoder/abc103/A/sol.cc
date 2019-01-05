#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(a <= b && a <= c){
    if(b <= c){
      cout << b - a + c - b << endl;
    }else{
      cout << c - a + b - c << endl; 
    }
  }else
  if(b <= a && b <= c){
    if(a <= c){
      cout << a - b + c - a << endl;
    }else{
      cout << c - b + a - c << endl;
    }
  }else
  if(c <= a && c <= b){
    if(a <= b){
      cout << a - c + b - a << endl;
    }else{
      cout << b - c + a - b << endl;
    }
  }
}