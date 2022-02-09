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

const int MAXN = 20 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main() {
	int tc;
	cin >> tc;
	getchar();
	string line;
	int res = 0, tot;
	unordered_map<long long, int> mp;
	function<void(int, int)> dfs = [&](int start, int layer){
		if(line[start] == '['){
			++start;
			dfs(start, layer + 1);
			int cnt = 0;
			while(line[start] != ',' || cnt != 0){
				cnt += line[start] == '[' ? 1 : line[start] == ']' ? -1 : 0;
				++start;
			}
			++start;
			dfs(start, layer + 1);
		}else{
			 long long num = atol(line.c_str() + start) << layer;
			 mp[num]++;
			 ++tot;
			 res = max(res, mp[num]);

		}
	};

	while(tc--){
		getline(cin, line);
		res = tot = 0;
		mp.clear();
		dfs(0, 0);
		cout << tot - res << '\n';	
	
	
	}	
}
