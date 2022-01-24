#include <bits/stdc++.h>

using namespace std;

int djs[1000];

void init(){
  for(int i = 0; i  < 1000; ++i)djs[i] = i;
}
int parent(int u){
  return u == djs[u] ? u : (djs[u] = parent(djs[u]));
}

int main(){
  int l, r, n;
  while(cin >> l && l && cin >> r >> n){
      unordered_map<int, vector<int>>m; 
      int a, b;
      init();
      while(n--){
        cin >> a >> b;
        b += 500;
        int pa = parent(a);
        int pb = parent(b);
        if(pa == pb) continue;
        djs[pa] = pb;
      }
      for(int i = 0; i < l; ++i){
        m[parent(i)].push_back(i);
      }
      for(int i = 0; i  < r; ++i){
        m[parent(i + 500)].push_back(i + 500);
      }
      int ans = 0;
      for(auto &p : m){
        if(p.second.size() == 1)continue;
        unordered_set<int> lu, ru;
        for(const int &u : p.second){
          if(u < 500)lu.insert(u);
          else ru.insert(u);
        }
        ans += min(lu.size(), ru.size());
      }
      cout << ans << '\n';
  }

}
