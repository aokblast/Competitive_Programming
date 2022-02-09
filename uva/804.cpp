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

struct E{
	vector<int> inp;
	vector<int> oup;
};

int main() {
	int np, nt, nf, tc = 1;
	int tok[MAXN];
   	E trans[MAXN];
	bool res = true;
	int dead = 0;
	auto bfs = [&](){
		res = true;
		for(dead = 0; dead < nf; ++dead){
			bool d = false;
			for(int i = 0; i < nt; ++i){
				bool can = true;
				int j = 0;
				for(; j < trans[i].inp.size(); ++j){
					
					if(--tok[trans[i].inp[j]] < 0){
						can = false;
						break;
					}
				}
				if(can){
					for(const int v: trans[i].oup)
						++tok[v];
					d = true;
					break;
				}else{
					for(int k = 0; k <= j; ++k)
						++tok[trans[i].inp[k]];
				}
			}
			if(!d){
				res = false;
				return;
			}
		}
	};

	while(cin >> np && np){
		for(int i = 1; i <= np; ++i)
			cin >> tok[i];
		cin >> nt;
		int tmp;
		for(int i = 0; i < nt; ++i){
			trans[i].inp.clear(), trans[i].oup.clear();
			while(cin >> tmp && tmp){
				if(tmp > 0)
					trans[i].oup.push_back(tmp);
				else
					trans[i].inp.push_back(-tmp);
					
			}
		}
		cin >> nf;
		bfs();
		cout << "Case " << (tc++) << ": " ;
		if(res){
			cout << "still live after " << dead << " transitions\n";
		}else{
			cout << "dead after " << dead << " transitions\n";
		}
		cout << "Places with tokens:";
		for(int i = 1; i <= np; ++i)
			if(tok[i])
				cout << " " << i << " (" << tok[i] << ")" ;
		cout << "\n\n";
		
	}
}
