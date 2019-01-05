#include <bits/stdc++.h>

using namespace std;

int frequency[5001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for(int t = 0; t < T; ++t){
    int N;
    cin >> N;
    memset(frequency, 0, sizeof frequency);
    for(int n = 0; n < N; ++n){
      int a, b;
      cin >> a >> b;
      for(int i = a; i <= b; ++i){
	frequency[i]++;
      }
    }
    int P;
    cin >> P;
    cout << "Case #" << (t + 1) << ": ";
    for(int p = 0; p < P; ++p){
      int query;
      cin >> query;
      cout << frequency[query] <<" ";
    }
    cout<<endl;
  }
  return 0;
}
