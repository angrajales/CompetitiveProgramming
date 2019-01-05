#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b;
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){                         
    cin >> a >> b;
    int k1 = max(a, b);
    int k2 = min(a, b);
    int k_ = (k2 - k1) / -2;
    int k__ = k1 - k_;
    if((k_ + k__ == a) && (k__ - k_ == b)){
      cout << max(k_, k__) << " " << min(k__, k_) << endl; 
    }else{
      puts("impossible");
    }
  }
  
}                                     