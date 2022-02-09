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

const int MAXN = (1 << 10) + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main() {
	int tc = 1, n;
	int arr[MAXN];
	int mp[10];
	while(cin >> n && n){
		cout << "S-Tree #" << tc++ << ":\n";
		char c;
		for(int i = 0; i < n; ++i){
			cin >> c >> c;  mp[i] = c -  '0';
		}
		int lim = 1 << n;
		for(int i = 0; i < lim; ++i){
			cin >> c; arr[i] = c - '0';
		}
		int m;
		cin >> m;
		string line;
		while(m--){
			int cur = 0;
			cin >> line;
			for(int i = 0; i < n; ++i){
				cur = (cur << 1) + line[mp[i] - 1] - '0';
			}
			cout << arr[cur];
		}
		cout << "\n\n";

		
	}

}
