#include<bits/stdc++.h>
using namespace std;

int head[20001], len, low[20001], dfn[20001], ans = 0, vis[20001];
int cnt[20001], n , m, tot = 0, root;

struct node{
	int v, next;
}e[200001];

void init(){
	len = 0;
	memset(head, -1, sizeof head);
}

void add(int u, int v){
	e[len].v = v;
	e[len].next = head[u];
	head[u] = len++;
}

void tarjan(int u, int pre){
	dfn[u] = low[u] = ++tot;
	int son = 0;
	for(int i = head[u]; ~i; i = e[i].next){
		if(pre == i) continue;
        int v = e[i].v;
		if(!dfn[v]){
            son++;
			tarjan(v, i ^ 1);
			low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u] && u != root) cnt[u] = 1;
        }
		else{
			low[u] = min(low[u], dfn[v]);
		}
	}
    if(u == root && son >= 2) cnt[u] = 1;
}

int main(){
	init();
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	
	for(int i = 1; i <= n; ++i){
		if(!dfn[i]){
			root = i;
			tarjan(i, -1);
		}
	}
    for(int i = 1; i <= n; ++i) ans += cnt[i];
    cout << ans << endl;
	for(int i = 1; i <= n; ++i){
		if(cnt[i]){
			cout << i << " ";
		}
	}
	return 0;
}
