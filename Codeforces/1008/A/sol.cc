#include <bits/stdc++.h>

using namespace std;

bool vowel(char a){
  return a == 'a' || a== 'e' || a=='i' || a == 'o' || a=='u';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a;
  cin >> a;
  bool can = true;
  for(int i = 0; i < a.size() - 1; ++i){
    if(!vowel(a[i])){
      if(!vowel(a[i+1]) && a[i]=='n'){
        continue;
      }else if(!vowel(a[i+1])){
        can = false;
      }
    }
  }
  if(!vowel(a[a.size()-1]) && a[a.size()-1] != 'n') can = false;
  puts(can ? "YES": "NO");
  return 0;
}