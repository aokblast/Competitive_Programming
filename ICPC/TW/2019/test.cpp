#include <bits/stdc++.h>

using namespace std;

int main(){
  unsigned long long n;
  cin >> n;
  unsigned long long ans = 0;
  for(unsigned long long i = n + 1;  i <= 100000; ++i){
    if(((i * n) % (i - n))  == 0) ans = max(ans, ((n * i) / (i - n)) ^ i);
  }
  cout << ans << endl;
}
