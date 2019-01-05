#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);                  
  int T;
  cin >> T;
  for(int i = 0; i < T; ++i){
    int n;
    cin >> n;
    char s[n];
    cin >> s;
    int t = 0;
    int res = 0;
    while(t < n){
      if(s[t] == '.'){
        res++;
        t += 3;
      }else{
        t++;
      }
    }
    cout << "Case " << (i + 1) << ": " << res << endl;
  }
  return 0;
}