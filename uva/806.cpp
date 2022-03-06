#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAXN = 1e2 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



int main() {
	int n, tc = 1;
	bool arr[MAXN][MAXN];
	function<void(int, int, int, int)> dfs1 = [&](int x, int y, int size, int val){
		if(!val){
			for(int i = x; i < x + size; ++i)
				for(int j = y; j < y + size; ++j)
					arr[i][j] = true;
		}else{
			size >>= 1;
			switch(val % 5){
				case 1:
					dfs1(x, y, size, val / 5);
					break;
				case 2:
					dfs1(x, y + size, size, val / 5);
					break;
				case 3:
					dfs1(x + size, y, size, val / 5);
					break;
				case 4:
					dfs1(x + size, y + size, size, val / 5);
					break;
			}
		}
	};
	vector<int> res;
	function<void (int, int, int, int, int)> dfs2 = [&](int x, int y, int size, int val, int layer){
		int v = arr[x][y];
		for(int i = x; i < x + size; ++i){
			for(int j = y; j < y + size; ++j){
				if(v != arr[i][j]){
					v = -1;
					break;
				}
			}
			if(v == -1)
				break;
		}
		if(v == -1){
			size >>= 1;
			int p = pow(5, layer);
			dfs2(x, y, size, val + p, layer + 1);
			dfs2(x, y + size, size, val + 2 * p, layer + 1);
			dfs2(x + size, y, size, val + 3 * p, layer + 1);
			dfs2(x + size, y + size, size, val + 4 * p, layer + 1);

		}else{
			if(v == 1)
				res.push_back(val);
		}
	};
	bool y = false;
	while(cin >> n && n){
		if(y)
			cout << '\n';
		y = true;
		cout << "Image " << tc++ << '\n';
		char c;
		if(n > 0){
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					cin >> c, arr[i][j] = c - '0';
			res.clear();
			dfs2(0, 0, n, 0, 0);
			sort(res.begin(), res.end());
			for(int i = 0; i < res.size(); ++i){
				cout << res[i] << ((i + 1) % 12 == 0 || (i + 1) == res.size() ? '\n' : ' ');
				
			}
			cout << "Total number of black nodes = " << res.size() << '\n';
		}else{
			n = -n;
			memset(arr, 0, sizeof(arr));
			int tmp;
			while(cin >> tmp && tmp != -1)
				dfs1(0, 0, n, tmp);
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++j)
					cout << (arr[i][j] ? '*' : '.');
				cout << '\n';
			}
		}
	}

	

}
