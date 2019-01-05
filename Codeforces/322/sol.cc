#include <bits/stdc++.h>

using namespace std;

int mxin(int a, int b, int c){
  return min(a, min(b, c));
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r, g, b, rp, gp, bp;
  cin >> r >> g >> b;
  rp = r, gp = g, bp = b;
  rp -= mxin(r, g, b);
  gp -= mxin(r, g, b);
  bp -= mxin(r, g, b);
  cout << (mxin(r, g, b) + rp/3 + gp/3 + bp/3) << endl;
  return 0;
}