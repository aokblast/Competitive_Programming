#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 1e5 + 5;


struct edge{
	int to;
	long long val;
	int rev;
};

int n, m, s, t;

vector<edge> adjs[MAXLEN];

int depth[MAXLEN];

bool bfs(){
  memset(depth, 0, sizeof(depth));		
	depth[s] =1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int f = q.front(); q.pop();
		for(edge &adj : adjs[f]){
			if(!depth[adj.to] && adj.val){
				depth[adj.to] = depth[f] + 1;
				q.push(adj.to);			
			}
		}
	
	}
	return depth[t];


}

long long dfs(int u = s, long long in = 0x3f3f3f3f3f3f3f){
	if(u == t) return in;
	if(in == 0) return 0;
	long long out = 0;
	for(edge &adj : adjs[u]){
		if((depth[adj.to] == (depth[u] + 1)) && adj.val){
			long long dist = dfs(adj.to, min(in, adj.val));
			adj.val -= dist;                
			adjs[adj.to][adj.rev].val += dist;
			in -= dist;
			out += dist;

		}
	
	}
	if(!out) depth[u] = 0;
	return out;
}

long long ans = 0;

void dinic(){
	while(bfs()){
		while(long long d = dfs()){
			ans += d;
		}
	}
}

void addedge(int from, int to, long long val){
	adjs[from].push_back({to, val, (int)adjs[to].size()});
  adjs[to].push_back({from, 0, (int)adjs[from].size() - 1});
	
}

long long k;

int main(){
	int tc, f, r;
	
	cin >> tc;
	while(tc--){
	 	cin >> n >> m >> s >> t >> k;
    for(int i = 1; i <= n; ++i)adjs[i].clear();
		while(m--){
			cin >> f >> r;	
			addedge(f, r, 1);
      addedge(r,f,1);
		}
		ans = 0;
		dinic();
		
		cout << ans * ((long long) ceil(k / 3.0)) << endl;
	}
	 
	

}
