#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8e3 + 5;

int main(){
	int t, n, tmp;
	cin >> t;

	while(t--){
		cin >> n;
		int sum = 0, sum1 = 0;
		vector<int> one1, two2;
		for(int i = 0; i < n; ++i){
			cin >> tmp;
			sum += tmp;
			if(tmp == 1)
				one1.push_back(i);
			
		}
		for(int i = 0; i < n; ++i){
			cin >> tmp;
			sum1 += tmp;
			if(tmp == 2)
				two2.psuh_back(i);
		}

		int res = 0, diff = sum - sum1;

		for(int i = 0; i < one1.size(); ++i){
			for(int j = 0; j < two2.size(); ++j){
				
			}
		}

		



		cout << res << '\n';

	}
	
}
