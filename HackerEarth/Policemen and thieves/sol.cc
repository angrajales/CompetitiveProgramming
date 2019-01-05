#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int N, K;
    cin >> N >> K;
    string a;
    int res = 0;
    getline(cin, a);
    for(int i = 0; i < N; ++i){
      getline(cin, a);
      string::iterator end_pos = remove(a.begin(), a.end(), ' ');
      a.erase(end_pos, a.end());
      //cerr << a << endl;
      int left = 0, right = 0;
      int k = a.size();
      bool was[a.size() + 1];
      memset(was, 0, sizeof was);
      while(left <= right){
        if(right >= a.size())
          break;
        if(a[left] == a[right]){
          if(right > left){
            left++;
          }else{
            right++;
          }
        }
        if(a[left] != a[right]){
          if(!was[left]){
            if(right - left <= K){
              was[left] = true;
              was[right] = true;
              left++;
              right++;
              cerr << "At "<< i << " ( " << left << ", " << right << ") "<< endl; 
              res++;
            }
          }else{
            left++;
          }
        }
      }
      //cerr << k << endl;
      //res += (k <= K);
    }
    cout << res << endl;
  }
  return 0;
}