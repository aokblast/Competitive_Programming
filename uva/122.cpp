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

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int val[MAXN];


int main() {
    int tc = 1;
    // cin >> tc;
    string node;


    while(cin >> node){
        bool ha = true;
        int tot = 0;        
        memset(val, -1, sizeof(val));    
        function<void(const int, const char *, int)> dfs = [&](const int v, const char *str, int cur){
            if(*str == 'L')
                dfs(v, str + 1, cur << 1);
            else if(*str == 'R')
                dfs(v, str + 1, (cur << 1) + 1);
            else{
                if(~val[cur])
                    ha = false;
                val[cur] = v;
                ++tot;
            }
        };
        do{
            if(node == "()")
                break;
            if(!ha)
                continue;
            size_t d = 0;
            int num = stoi(node.c_str() + 1, &d);
            dfs(num, node.c_str() + d + 2, 1);
        }while(cin >> node);
        if(ha){
            queue<int> q;
            string ans;
            int cnt  = 0;
            if(val[1] != -1)
                q.push(1);

            while(!q.empty()){
                int f = q.front();q.pop();
                ans += to_string(val[f]) + ' ';
                ++cnt;
                if(~val[f << 1])
                    q.push(f << 1);
                if(~val[(f << 1) + 1])
                    q.push((f << 1) + 1);
            }
            if(cnt != tot)
                cout << "not complete\n"; 
            else{
                ans.pop_back();
                cout << ans << '\n';

            }


        }else{
            cout <<  "not complete\n";
        }


        


    }
}
