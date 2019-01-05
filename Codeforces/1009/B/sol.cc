#include <bits/stdc++.h>

using namespace std;

bool valid(char a, char b){
  return (a == '0' && b == '1') |
         (a == '1' && b == '0') | 
         (a == '1' && b == '2') | 
         (a == '2' && b == '1');
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  char prev = s[0];
  string ns = "";
  for(int i = 1; i < s.size(); ++i){
    if(!valid(prev, s[i])) ns += prev, prev = s[i];
    if(prev > s[i] && valid(prev, s[i])){
      ns += s[i];
      continue;
    }
    if(s[i] >= prev && valid(prev, s[i])){
      ns += prev;
      prev = s[i];
    }
  }
  cout << ns + prev << endl;
  return 0;
}