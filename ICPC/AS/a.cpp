#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	long long res = 0;

	cin >> n >> m;
	
	for(int i = 2; i <= n; i += 2)
		res += 1ll * (m + 1) * (n - i + 1);

	for(int i = 2; i <= m; i += 2)
		res += 1ll * (n + 1) * (m - i + 1);

	for(int i = 2; i <= n; i += 2)
		for(int j = 2; j <= m; j += 2)
			res += 2ll * (n - i + 1) * (m - j + 1);

	cout << res << '\n';


}
