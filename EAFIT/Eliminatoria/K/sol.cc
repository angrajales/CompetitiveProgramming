#include <bits/stdc++.h>

using namespace std;

struct Trie{
  bool esta;
  map<char, Trie> hijos;
  Trie(){ esta = false; }
  void insertar(const string &s, int pos){
    if(pos < int(s.size()))
      hijos[s[pos]].insertar(s, pos + 1);
    else
      esta = true;
  }
  void insertar(const string &s){
    insertar(s, 0);
  }
  bool buscar(const string &s, int pos){
    if(pos < int(s.size()))
      return hijos.find(s[pos]) != hijos.end() &&
         hijos[s[pos]].buscar(s, pos + 1);
    else
      return esta;
  }
  bool buscar(const string &s){
    return buscar(s, 0);
  }
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for(int m = 0; m < t; ++m){
    Trie *t;
    vector<string> ss;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
      string s;
      cin >> s;
      ss.push_back(s);
    }
    sort(ss.begin(), ss.end());
    reverse(ss.begin(), ss.end());
    int cnt = 0;
    for(int i = 0; i < n; ++i){
      cerr << "To " << ss[i] << endl;
      if(t->buscar(ss[i])) cnt++;
      t->insertar(ss[i]);
    }
    puts(cnt == n ? "Yes": "No");
  }
  return 0;
}