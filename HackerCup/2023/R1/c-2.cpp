#include <bits/stdc++.h>

using namespace std;
constexpr int SZ = 4000000 + 1;
void solve() {
		bitset<SZ> bits;
		int n;
		cin >> n;
		char c;
		for(int i = 1; i <= n; ++i)
				cin >> c, bits[i] = c == '1';
		unordered_set<int> st;
		for(int i = 1; i <= n; ++i) {
				if(bits[i]) {
						st.insert(i);
						for(int j = i; j <= n; j += i)
								bits[j] = ~bits[j];
				}
		}

		int q;
		cin >> q;
		long long res = 0;
		for(int i = 0; i < q; ++i) {
				int t;
				cin >> t;
				if(st.count(t))
						st.erase(t);
				else
						st.insert(t);
				res += st.size();
		}

		cout << res << endl;
}


int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr), cout.tie(nullptr);
		int tc;
		cin >> tc;

		for(int i = 1; i <= tc; ++i) {
				cout << "Case #" << i << ": ";
				solve();
		}
		return 0;
}
