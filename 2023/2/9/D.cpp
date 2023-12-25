#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
#define maxn 10000
using namespace std;

int k, n[3], t[3], sta[maxn + 5], st[4][maxn + 5], top[4], res[3];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    read(k);
    For(i, 0, 2) read(n[i]), res[i] = n[i];
    For(i, 0, 2) read(t[i]);
    priority_queue<pair<int, int> > q;
    For(i, 1, k) st[0][++top[0]] = i;
    LL now = 0;
    while(q.size() || top[0] || top[1] || top[2]){
        For(o, 0, 2){
            while(res[o] && top[o]){
                int u = st[o][top[o]];
                res[o]--;
                top[o]--;
                q.push(mp(-now - t[o], u));
            }
        }
        if(q.size()){
            pair<int, int> pa = q.top(); q.pop();
            now = -pa.fir;
            int u = pa.sec;
            res[sta[u]]++;
            sta[u]++;
            st[sta[u]][++top[sta[u]]] = u;
        }
    }
    printf("%lld\n", now);
    return 0;
}
