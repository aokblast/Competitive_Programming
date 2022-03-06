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

struct card{
	char rk, suit;
	bool operator==(const card &c) const {
		return rk == c.rk || suit == c.suit;
	}
}; 
vector<card> cards[MAXN];

int main() {
	char c1,c2;
	while(true){
		cards[0].clear();
		if(cin >> c1 && c1 == '#')
			break;
		cin >> c2;
		cards[0].push_back({c1, c2});
		for(int i = 1; i < 52; ++i)
			cin >> c1 >> c2, cards[i].clear(), cards[i].push_back({c1, c2});
		auto match = [&](int idx, int s){
			int cnt = 0, l = idx;
			while(cnt < s && l >= 0){
				cnt += !cards[--l].empty();
			}
			if(l >= 0 && cards[l].back() == cards[idx].back()){
				cards[l].push_back(cards[idx].back()), cards[idx].pop_back();
				return l;
			}else 
				return -1;
		};
		for(int i = 1; i < 52; ){
			while(i < 52 && cards[i].empty())
				++i;
			if(i == 52)
				break;
			int sv = match(i, 3);
			if(sv >= 0){
				i = sv;
				continue;
			}
			
			sv = match(i, 1);
			if(sv >= 0){
				i = sv;
				continue;
			}
			++i;
		}
		
		
		vector<int> res;
		for(int i = 0; i < 52; ++i)
			if(!cards[i].empty())
				res.push_back(cards[i].size());
			

		cout << res.size() << " pile" << (res.size() >= 2 ? "s" : "") << " remaining:";
		for(const int num : res)
			cout << " " << num;
		
		cout << '\n';
	}

	

}
