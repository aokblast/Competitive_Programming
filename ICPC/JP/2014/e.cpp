#include <bits/stdc++.h>

using namespace std;

int arr[9];
int tmp[9];

int getHash(int *a){
  int ans = 0;
  int loc = 0;
  for(int i = 0; i < 9; ++i)ans |= (a[i] == 0 ? (loc = i, 0) : ((a[i] - 1) << (3 * i)));
  ans = (ans << 4) | loc;
  return ans;
}

int getArr(int num){
  int loc = num & 0xF;
  num >>= 4;
  for(int i = 0; i < 9; ++i)arr[i] = (num & 0x7) + 1, num >>= 3;
  arr[loc] = 0;
  return loc;

}

void update(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>  &q, unordered_set<int> &vis, unordered_map<int, int> &dis, int a, int val){
  if(vis.find(a) == vis.end() && (dis.find(a) == dis.end() || dis[a] > val)) dis[a] = val, q.push({val, a});
}


int main(){
  int ch, cv;
  while(cin >> ch >> cv && (ch || cv)){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    unordered_set<int> vis;
    unordered_map<int, int> dist;
    for(int i = 0; i < 9; ++i) cin >> arr[i];
    for(int i = 0; i < 9; ++i) cin >> tmp[i];
    int res = getHash(tmp);
    q.push({0, getHash(arr)});
    dist[getHash(arr)] = 0;
    while(!q.empty()){
      auto front = q.top(); q.pop();
      if(vis.find(front.second) != vis.end() )continue;
      vis.insert(front.second);
      if(front.second == res){
        cout <<  front.first << '\n';
        break;
      }
      int st = getArr(front.second);
      
      swap(arr[st], arr[(st + 1) % 9]);
      int nexts = getHash(arr);
      update(q, vis, dist, nexts, front.first + ch);
      swap(arr[st], arr[(st + 1) % 9]);
      
      swap(arr[st], arr[(st + 8) % 9]);
      nexts = getHash(arr);
      update(q, vis, dist, nexts, front.first + ch);
      swap(arr[st], arr[(st + 8) % 9]);
      
      swap(arr[st], arr[(st + 3) % 9]);
      nexts = getHash(arr);
      update(q, vis, dist, nexts, front.first + cv);
      swap(arr[st], arr[(st + 3) % 9]);
      
      swap(arr[st], arr[(st + 6) % 9]);
      nexts = getHash(arr);
      update(q, vis, dist, nexts, front.first + cv);
    }

  }

}
