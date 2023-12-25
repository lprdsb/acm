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
#define maxn 500000
using namespace std;

int n, k, rt, ch[maxn + 5][2], fa[maxn + 5];
LL f[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int as[maxn + 5], lpr[maxn + 5], st[maxn + 5], top = 0, fla, h[maxn + 5];
void sol(int x){
    if(as[x]) return;
    top = 0;
    int fl = 0;
    while(x){
        st[++top] = x;
        if(!as[x]) fl = top;
        if(x != rt && fa[x] < x && !as[fa[x]]) return;
        x = fa[x];
    }
    if(fl == top){
        // cout << f[top] << endl;
        if(f[top] <= k){
            k -= f[top];
            For(i, 1, top){
                as[st[i]] = 1;
                lpr[st[i]] = i;
                if(i >= 2 && ch[st[i]][1]) lpr[ch[st[i]][1]] = i - 2;
            }
        }
    }
    else{
        if(lpr[st[fl]] >= fl){
            int res = lpr[st[fl]] - 1;
            // if(st[1] == 14) cout << lpr[17] << endl;
            Rof(i, fl, 1){
                as[st[i]] = 1;
                if(ch[st[i]][0]){
                    if(h[ch[st[i]][0]] >= lpr[st[i]] - 1){
                        lpr[ch[st[i]][0]] = lpr[st[i]] - 1;
                        if(ch[st[i]][1]) lpr[ch[st[i]][1]] = lpr[st[i]] - 2;
                    }
                    else{
                        lpr[ch[st[i]][0]] = lpr[st[i]] - 2;
                        lpr[ch[st[i]][1]] = lpr[st[i]] - 1;
                        // cout << ch[st[i]][1] << " " << res << " " << i << endl;
                    }
                }
                else lpr[ch[st[i]][1]] = lpr[st[i]] - 1;
            }
        }
        else{
            LL tem = f[fl] - f[lpr[st[fl]]];
            if(tem > k) return;
            For(i, fl, top - 1){
                int to = st[i] > st[i + 1];
                if(to){
                    if(lpr[ch[st[i + 1]][0]] < i - 1) return;
                }
                else{
                    tem += max(0ll, f[i - 1] - f[lpr[ch[st[i + 1]][1]]]);
                    if(tem > k) return;
                }
            }
            k -= tem;
            For(i, 1, fl){
                as[st[i]] = 1;
                lpr[st[i]] = i;
                if(i >= 2 && ch[st[i]][1]) lpr[ch[st[i]][1]] = i - 2;
            }
            For(i, fl, top - 1){
                int to = st[i] > st[i + 1];
                if(lpr[st[i + 1]] < i + 1) lpr[st[i + 1]] = i + 1;
                if(!to && ch[st[i + 1]][1] && lpr[ch[st[i + 1]][1]] < i - 1) lpr[ch[st[i + 1]][1]] = i - 1; 
            }
        }
    }
}

void dfs(int u){
    h[u] = 1;
    For(i, 0, 1) if(ch[u][i]){
        dfs(ch[u][i]);
        h[u] = max(h[u], h[ch[u][i]] + 1);
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    f[1] = 1;
    f[2] = 2;
    For(i, 3, 50) f[i] = f[i - 1] + f[i - 2] + 1;
    read(n); read(k); fla = k;
    For(i, 1, n){
        int x; read(x);
        if(x == -1) rt = i;
        else fa[ch[x][x < i] = i] = x;
    }
    dfs(rt);
    For(i, 1, n) sol(i);
    // cout << k << endl;
    For(i, 1, n) printf("%d", as[i]);
    return 0;
}
