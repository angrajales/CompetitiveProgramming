#include <bits/stdc++.h>

using namespace std;

int main(){
  string a, b;
  cin >> a >> b;
  for(int i = 0; i < a.size(); ++i){
    string nk = a.substr(i, a.size() - i) + a.substr(0, i);
    if(nk == b) return 0 * puts("Yes");
  }
  puts("No");
}