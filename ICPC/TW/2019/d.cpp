#include <bits/stdc++.h>

using namespace std;

int main(){
  stringstream res;
  string str;
  for(int i = 0 ; i < 3; ++i){
    cin >> str;
    if(str == "bubble" || str == "tapioka")continue;
    res << str << " ";
  }
  str = res.str();
  if(!str.empty())str.pop_back();
  cout << (str.empty() ? "nothing\n" : str + "\n");
}
