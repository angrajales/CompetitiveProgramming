#include <bits/stdc++.h>

using namespace std;
/*
  ID: andergr2
  PROB: palsquare
  LANG: C++
*/


bool pal(string &d){
  for(int i = 0; i < d.size(); ++i){
    if(d[i] != d[d.size() - i - 1]){
      return false;
    }
  }
  return true;
}

string res;
void printInBase(int x, int y)
{
   if ( x < y )
   {
      res += to_string(x);
      return;
   }

   int rem = x%y;
   printInBase(x/y, y);
   res += to_string(rem);
}


int main(){
  freopen("palsquare.in", "r", stdin);
  freopen("palsquare.out", "w", stdout);
  int b;
  cin >> b;
  for(int i = 1; i <= 300; ++i){
    int p = i, q = i;
    string sq;
    res = "";
    printInBase(p * p, b);
    sq = res;
    if(pal(res)){
      res = "";
      printInBase(q, b);
      cout << res << " " << sq << endl;
    }
  }
  return 0;
}