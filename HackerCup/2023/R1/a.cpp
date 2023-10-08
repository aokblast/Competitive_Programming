#include <bits/stdc++.h>

using namespace std;

void solve() {
		int n;
		cin >> n;
		vector<int> dis(n);

		for(auto &e : dis)
				cin >> e;
		sort(dis.begin(), dis.end());

		if(n == 5)
				cout  << setprecision(10) << max(((double)dis[n - 1] + dis[n - 3]) / 2 - ((double)dis[1] + dis[0]) / 2
								, ((double)dis[n - 1] + dis[n - 2]) / 2 - ((double)dis[2] + dis[0]) / 2) << endl;
		else
				cout  << setprecision(10) << ((((double)dis[n - 1] + dis[n - 2]) / 2)) - (((double)dis[1] + dis[0]) / 2) << endl;
}


int main() {
		int tc;
		cin >> tc;

		for(int i = 1; i <= tc; ++i) {
				cout << "Case #" << i << ": ";
				solve();
		}
		return 0;
}
