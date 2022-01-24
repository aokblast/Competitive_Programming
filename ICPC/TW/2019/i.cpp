#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 2e3 + 5;

int mp[MAXLEN], ma, n, arr[MAXLEN];

vector<int> vec;
set<vector<int>> ans;

void dfs(int cur, int maxN){
  if(cur == n){
    vector<int> v = vec;
    sort(v.begin(), v.end());
    ans.insert(v);
    return;
  }
  while(mp[maxN] == 0) --maxN;
  if(mp[maxN] > 2)return;
  if(mp[maxN] == 1 || (mp[maxN] == 2 && maxN * 2 == ma)){
    vec.push_back(maxN);
    bool canAdd = true;
    for(int i = 0; i < cur; ++i){
      if((--mp[abs(vec[cur] - vec[i])]) < 0)canAdd = false;
    }
    if(canAdd) dfs(cur + 1, maxN);
    for(int i = 0; i < cur; ++i){
      ++mp[abs(vec[cur] - vec[i])];
    }
    vec.pop_back();
    vec.push_back(ma - maxN);
    canAdd = true;
    for(int i = 0 ; i < cur; ++i){
      if((--mp[abs(vec[cur] - vec[i])]) < 0) canAdd = false;
    }   
    if(canAdd) dfs(cur + 1, maxN);
    for(int i = 0 ; i < cur; ++i){
      ++mp[abs(vec[cur] - vec[i])];
    }
    vec.pop_back();
    
  }else{
    vec.push_back(maxN);
    vec.push_back(ma - maxN);
    bool canAdd = true;
    for(int i = 0; i < cur; ++i){
      if((--mp[abs(vec[cur] - vec[i])]) < 0) canAdd = false;
      if((--mp[abs(vec[cur + 1] - vec[i])]) < 0) canAdd = false;
    }
    if((--mp[abs(vec[cur + 1] - vec[cur])]) < 0) canAdd = false;
    if(canAdd)dfs(cur + 2, maxN);
    for(int i = 0; i < cur; ++i){
      ++mp[abs(vec[cur] - vec[i])], ++mp[abs(vec[cur + 1] - vec[i])];
    }
    ++mp[abs(vec[cur + 1] - vec[cur])];
    vec.pop_back();
    vec.pop_back();
  }

}

int main(){
  cin >> n;

  for(int i = 1; i <= (n) * (n - 1) / 2; ++i){
    cin >> arr[i];     
    ma = max(ma, arr[i]);
    ++mp[arr[i]];
    if(arr[i] >= 1000){
      cout << 0 << '\n';
      return 0;
    }
  }

  vec.push_back(0), vec.push_back(ma);
  --mp[ma];
  if(mp[ma]){
    cout << 0 << '\n';
    return 0;
  }
  dfs(2, ma);
  vector<vector<int>> fuck;
  for(const vector<int> &v : ans) fuck.push_back(v);
  sort(fuck.begin(), fuck.end());
  cout << fuck.size() << '\n';
  for(const auto &v : fuck){
    for(const int &num : v){
      cout << num << ' ';
    }
    cout << '\n';
  }
}
