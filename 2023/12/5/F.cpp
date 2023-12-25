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
using namespace std;

int T, n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

#define maxn 100000
int a[maxn + 5], in[maxn + 5];
vector<int> b[maxn + 5], ch[maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, n){
            int p; read(p);
            b[i].resize(p + 1);
            For(j, 1, p) read(b[i][j]);
        }
        Rof(i, n, 1){
            For(j, 1, b[i].size() - 1){
                if(a[b[i][j]]) ch[i].pb(a[b[i][j]]), in[a[b[i][j]]]++;
                else a[b[i][j]] = i;
            }
        }
        queue<int> q;
        For(i, 1, n) if(!in[i]) q.push(i);
        int fl = 0;
        vector<int> as;
        while(q.size()){
            int u1 = q.front(), u2 = -1; q.pop();
            if(!fl && q.size()){
                u2 = q.front(); q.pop();
                if(u1 > u2) swap(u1, u2);
                fl = 1;
                as.pb(u2);
            }
            as.pb(u1);
            for(auto v : ch[u1]){
                in[v]--;
                if(!in[v]) q.push(v);
            }
            if(u2 != -1){
                for(auto v : ch[u2]){
                    in[v]--;
                    if(!in[v]) q.push(v);
                }
            }
        }
        if(!fl) puts("No");
        else{
            puts("Yes");
            For(i, 0, n - 1){
                printf("%d", as[i]);
                if(i != n - 1) printf(" ");
            }
            puts("");
        }
        For(i, 1, m) a[i] = 0;
        For(i, 1, n) ch[i].resize(0);
    }
}
