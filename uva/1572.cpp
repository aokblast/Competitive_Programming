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

const int MAXN = 52;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


int main(){

    int n;
    int rd[MAXN];
    bool adjs[MAXN][MAXN];
    string s;

    auto top = [&](){
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < MAXN; ++i)
            if(rd[i] == 0)
                q.push(i);

        while(!q.empty()){
            int t = q.front(); q.pop();
            ++cnt;
            for(int i = 0; i < MAXN; ++i){
                if(adjs[t][i] && (--rd[i]) == 0)
                    q.push(i);

            }
        }
        return cnt == MAXN;
    };

    while(cin >> n){
        
        memset(rd, 0, sizeof(rd));
        memset(adjs,0 , sizeof(adjs));

        for(int c = 0; c < n; ++c){
            cin >> s;
            for(int i = 0; i < 4; ++i){
                if(s[i << 1] == '0')
                    continue;
                int f = (s[i << 1] - 'A') * 2 + (s[i * 2 + 1] == '+' ? 1 : 0);            
                for(int j = 0; j < 4; ++j){
                    if(i == j || s[j << 1] == '0')
                        continue;
                    int t = (s[j << 1] - 'A') * 2  + (s[j * 2 + 1] == '+' ? 0 : 1);
                    (rd[t] += adjs[f][t] == false), adjs[f][t] = true;
                }
            }
        } 

        cout << (!top() ? "unbounded" : "bounded") << '\n';
    }








}
