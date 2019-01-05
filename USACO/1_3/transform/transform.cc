#include <bits/stdc++.h>

using namespace std;

/*
  ID: andergr2
  PROB: transform
  LANG: C++
*/

const int N = 11;
char data[N][N];
char to[N][N];
char conv[N][N];
char datap[N][N];

int n;

bool cmp(){
  for(int i = 0; i < n; ++i)
    if(!strcmp(conv[i], to[i]) == 0) return false;
  return true;
}

void rot90(){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      conv[j][n - i - 1] = datap[i][j];
    }
  }
}

void cpy(){
  for(int i = 0; i < n; ++i){
    strcpy(datap[i], conv[i]);
  }
}
void cpyd(){
  for(int i = 0; i < n; ++i){
    strcpy(datap[i], data[i]);
  }
}

void rot180(){
  rot90();
  cpy();
  rot90();
  for(int i = 0; i < n; ++i){
    cerr << conv[i] << endl;
  }
  cpyd();
}

void rot270(){
  rot90();
  cpy();
  rot90();
  cpy();
  rot90();
  cpyd();
}

void reflect(){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      conv[i][n - j - 1] = datap[i][j];
    }
  }
}

void combine1(){
  reflect();
  cpy();
  rot90();
  cpyd();
}

void combine2(){
  reflect();
  cpy();
  rot180();
  cpyd();
}

void combine3(){
  reflect();
  cpy();
  rot270();
  cpyd();
}


int main(){
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> data[i];
    strcpy(to[i], conv[i]);
  }
  cpyd();
  for(int i = 0; i < n; ++i){
    cin >> to[i];
  }
  if(cmp()){
    cout << 6 << endl;
    return 0;
  }
  rot90();
  if(cmp()){
    cout << 1 << endl;
    return 0;
  }
  rot180();
  if(cmp()){
    cout << 2 << endl;
    return 0;
  }
  rot270();
  if(cmp()){
    cout << 3 << endl;
    return 0;
  }
  reflect();
  if(cmp()){
    cout << 4 << endl;
    return 0;
  }
  combine1();
  if(cmp()){
    cout << 5 << endl;
    return 0;
  }
  combine2();
  if(cmp()){
    cout << 5 << endl;
    return 0;
  }
  combine3();
  if(cmp()){
    cout << 5 << endl;
    return 0;
  }
  cout << 7 << endl;
  return 0;
}