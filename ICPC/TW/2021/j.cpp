#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8e3 + 5;

int main(){
	long tc, tmp, n, s, p;
	cin >> tc;
	while(tc--){
		cin >> n >> s >> p;
		for(int i = 0; i < s; ++i)
			cin >> tmp;
		cout << (2 * (n - 1) * (n - s - 1 + p - 1) + 2 * (n - p) * p) << '\n';
	}
	
}
