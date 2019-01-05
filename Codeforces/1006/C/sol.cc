#include <bits/stdc++.h>

using namespace std;

int a[200001];
long long int sum[200002];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  sum[0] = 0;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  sum[n + 1] = sum[n];
  int left = 0, right = n + 1;
  long long int sum1 = 0, sum3 = 0, res = 0;
  while(left <= right && left <= n && right >= 1){
    sum1 = sum[left] - sum[0];
    sum3 = sum[n + 1] - sum[right];
    if(sum1 == sum3){
      res = sum1;
      right--;
      left++;
    }
    if(sum1 < sum3){
      left++;
    }
    if(sum3 < sum1){
      right--;
    }
  }
  cout << res << endl;
  return 0;

} 