#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 1e6 + 5;

pair<long long, long long> arr[MAXLEN];

long long gcd(long long a, long long b){
  return b == 0 ? a : gcd(b, a % b);
}

int main(){
  int n;
  long long k, g;
  cin >> n >> k;
  long long sq = sqrt(k);
  vector<long long> s;

  for(long long i = 2; i < sq; ++i){
    if(!(k % i))s.push_back(i), s.push_back(k / i);
  }
  if(sq * sq == k)s.push_back(sq);
  s.push_back(k);
  cin >> arr[0].second;
  g = arr[0].second;
  for(int i = 1; i < n; ++i)cin >> arr[i].second, g = gcd(g, arr[i].second);
  for(int i = 0; i < n; ++i)cin >> arr[i].first;
  sort(arr, arr + n);
  long long ans = 0, x = 1, y = 0;
  long long i = 0;
  while(g != 1 && i < n){
    long long gu = gcd(g, arr[i].second);
    if(gu <= k) {g /= gu; goto calc;}
    else{
      long long gu2;
      for(auto iter = s.rbegin(); iter != s.rend(); ++iter){
        
        if((gu2 = gcd(gu, *iter)) != 1){
          g /= gu2; goto calc;
        }
      }
    }
    ++i;
    continue;
calc:
    ans += y + arr[i].first * (x++), y += arr[i].first, ++i;
  }
  cout << (g == 1 ? ans : -1) << '\n';



    
}
