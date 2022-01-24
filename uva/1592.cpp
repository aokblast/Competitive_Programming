#include <bits/stdc++.h>

using namespace std;
unordered_map<string, int> idm;
int idNum = 0;

const int maxn = 1e4 + 5;

int mat[maxn][15];

int getID(string &s){
  return (idm.find(s)  == idm.end() ? (idm[s] = ++idNum) :  idm[s]);
}


int main(){
  int n, m;
  string line, tok;
  while(cin >> n >> m){
    getchar();
    idm.clear(), idNum = 0;
    for(int i = 0; i < n; ++i){
      getline(cin, line);
      auto iter = line.begin();
      for(int j = 0; j < m; ++j){
        while(*iter != ',' && *iter != '\0'){
          tok += *iter;
          ++iter;
        }
        ++iter;
        mat[i][j] = getID(tok);
        tok.clear();
      }
    }
    for(int c1 = 0; c1 < m; ++c1){
      for(int c2 = c1 + 1; c2 < m; ++c2){
        map<pair<int, int>, int> cn;
        for(int i = 0;i < n; ++i){
          auto p = make_pair(mat[i][c1], mat[i][c2]);
          if(cn.find(p) != cn.end()){
            cout << "NO\n" << (cn[p] + 1) << " " <<  (i + 1) << '\n' << (c1 + 1) << " " << (c2 + 1) << '\n';
            goto end;
          }
          cn[p] = i;
        }
      }
    }
    cout << "YES" << '\n';
end:
    1;
  }


}
