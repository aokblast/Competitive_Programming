#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 100 + 5;

int s1[MAXLEN];
int s2[MAXLEN];

int arr[MAXLEN][MAXLEN];

struct Node{
  int a,  b, id;
  bool operator<(const Node &n) const{
    return a == n.a ? b < n.b : a < n.a;
  }
};

int main(){
  priority_queue<Node> q;
  int n;
  cin >> n;
  if(n == 1){
    cout << "1\n";
    return 0;
  }
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      cin >> arr[i][j];
      s2[j] -= arr[i][j];
      s2[i] += arr[i][j];
    }
  }
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= i; ++j){
      if(arr[i][j] > arr[j][i]){
        s1[i] += 3;
      }else if(arr[i][j] == arr[j][i]){
        s1[i] += 1;
        s1[j] += 1;
      }else{
        s1[j] += 3;
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    q.push({s1[i],  s2[i], i});
  }
  auto n1 = q.top(); q.pop();
  auto n2 = q.top(); q.pop();
  if(n1.a == n2.a){
    cout << (n1.b == n2.b ? string("play-offs") : to_string(n1.id)) << '\n';
  }else {
    cout << n1.id << '\n';
  }

}
