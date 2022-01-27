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

const int MAXN = 1e3 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int progs, locked, t0, t1, t2, t3, t4, qu;
int vars[26];
int cur[MAXN];
vector<string> stats[MAXN];
deque<int> q, bq;

void exec(int pid){
    int t  = qu;
    while(t > 0){
        string &com = stats[pid][cur[pid]];
        switch(com[2]){
            case '=':
                vars[com[0] - 'a'] = atoi(com.c_str() + 4);
                t -= t0;
                break;
            case 'l':
                locked = 0;
                if(!bq.empty()){
                    q.push_front(bq.front());
                    bq.pop_front();
                }
                t -= t3;
                break;
            case 'c':
                if(locked){
                    bq.push_back(pid);
                    return;
                }
                locked = 1;
                t -= t2;
                break;
            case 'i':
                cout << (pid + 1) << ": " << vars[com[6] - 'a'] << '\n';
                t -= t1;
                break;
            case 'd':
                return;
        }
        cur[pid]++;
    }
    q.push_back(pid);
}

void solve() {
    string line;
    cin >> progs >> t0 >> t1 >> t2 >> t3 >> t4 >> qu;
    q.clear();
    bq.clear();
    getchar();
    for(int i = 0; i < progs; ++i){
        stats[i].clear();
        q.push_back(i);
        while(getline(cin, line)){
            stats[i].push_back(line);
            if(line[2] == 'd')
                break;
        }
    
    }
    locked = 0;
    while(!q.empty()){
        int pid = q.front(); q.pop_front();
        exec(pid);
    }

}

int main() {
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        memset(vars, 0, sizeof(vars));
        memset(cur, 0, sizeof(cur));
        solve();
        if(t != tc)cout << '\n';
      // cout << "Case #" << t << ": ";
    }
}
