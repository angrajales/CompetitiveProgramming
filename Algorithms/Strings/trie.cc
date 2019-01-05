#include <map>
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
  return 0;
}