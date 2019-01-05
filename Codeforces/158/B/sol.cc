#include <bits/stdc++.h>

using namespace std;

int a[100001];
int cnt[5];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  memset(cnt, 0, sizeof cnt);
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    a[i] = x;
    cnt[a[i]]++;
  }
  int res = 0;
  cnt[0] = n;
  res += cnt[2] / 2;
  cnt[2] = (cnt[2] & 1);
  for(int i = 1; i <= 4; ++i){
    if(i == 2) continue;
    while(cnt[i] > 0 && cnt[4 - i] > 0){
      res++;
      cnt[i] --;
      cnt[4 - i] --;
    }
  }
  if(cnt[3] > 0){
    res += cnt[3];
  }
  if(cnt[2] > 0){
    int sim = 2;
    while(sim < 4 && cnt[1] > 0){
      sim += 1;
      cnt[1]--;
    }
    res += 1;
  }
  while(cnt[1] >= 4){
    cnt[1] -= 4;
    res++;
  }
  if(cnt[1] > 0) res++; 
  cout << res << endl;
  return 0;
}