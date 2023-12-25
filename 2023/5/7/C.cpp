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
#define maxn 2000000
using namespace std;

int n, m, ch[maxn + 5][26], tot = 2, bas = 133331, dep[maxn + 5], ok[maxn + 5], as[maxn + 5], to[2][maxn + 5];
int mod[2] = {998244353, 1000000007};
char s[maxn + 5];
struct Hsh{
    LL v1, v2;
} val[maxn + 5], pw[maxn + 5], ipw[maxn + 5];
Hsh operator * (cst Hsh &x, cst int &y){return {1ll * x.v1 * y % mod[0], 1ll * x.v2 * y % mod[1]};}
Hsh operator * (cst Hsh &x, cst Hsh &y){return {1ll * x.v1 * y.v1 % mod[0], 1ll * x.v2 * y.v2 % mod[1]};}
Hsh operator + (cst Hsh &x, cst int &y){return {(1ll * x.v1 + y) % mod[0], (1ll * x.v2 + y) % mod[1]};}
Hsh operator - (cst Hsh &x, cst Hsh &y){return {(1ll * x.v1 - y.v1 + mod[0]) % mod[0], (1ll * x.v2 - y.v2 + mod[1]) % mod[1]};}
bool operator < (cst Hsh &x, cst Hsh &y){
    if(x.v1 != y.v1) return x.v1 < y.v1;
    return x.v2 < y.v2;
}
map<Hsh, int> ma[2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fail[maxn + 5], fail_ch[maxn + 5][26];
int st[maxn + 5], top = 0;
void dfs(int u, int ty){
    if(ok[u]){
        if(ty){
            int now = fail[u];
            while(now > 2){
                if(ok[now]) ma[1][(val[u] - val[now]) * ipw[dep[now]]] = 1;
                now = fail[now];
            }
        }
        else{
            For(i, 1, top) ma[0][val[u] - pw[dep[u] - dep[st[i]]] * val[st[i]]] = 1;
            st[++top] = u;
        }
    }
    For(i, 0, 25){
        int v = ch[u][i];
        if(!v) continue;
        dfs(v, ty);
    }
    if(!ty && ok[u]) top--;
}

void dfs1(int u, int ty){
    if(ok[u]){
        if(!ty){
            For(i, 1, top){
                if(ma[1][val[u] - pw[dep[u] - dep[st[i]]] * val[st[i]]]) as[u] = as[st[i]] = 1;
            }
            st[++top] = u;
        }
        else{
            int now = fail[u];
            while(now > 2){
                if(ok[now]){
                    if(ma[0][(val[u] - val[now]) * ipw[dep[now]]]) as[u] = as[now] = 1;
                }
                now = fail[now];
            }
        }
    }
    For(i, 0, 25){
        int v = ch[u][i];
        if(!v) continue;
        dfs1(v, ty);
    }
    if(!ty && ok[u]) top--;
}

void build(){
    memcpy(fail_ch, ch, sizeof ch);
    queue<int> q;
    For(i, 0, 25){
        if(ch[1][i]){
            fail[ch[1][i]] = 1;
            q.push(ch[1][i]);
        }
        else fail_ch[1][i] = 1;
        if(ch[2][i]){
            fail[ch[2][i]] = 2;
            q.push(ch[2][i]);
        }
        else fail_ch[2][i] = 2;
    }
    while(q.size()){
        int u = q.front(); q.pop();
        For(i, 0, 25){
            int v = ch[u][i];
            if(v){
                fail[v] = fail_ch[fail[u]][i];
                q.push(v);
            }
            else fail_ch[u][i] = fail_ch[fail[u]][i];
        }
    }
}

int fp(int x, int y, int modi){
    int asi = 1;
    while(y){
        if(y & 1) asi = 1ll * asi * x % modi;
        x = 1ll * x * x % modi;
        y >>= 1;
    }
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    pw[0] = {1, 1};
    For(i, 1, maxn) pw[i] = pw[i - 1] * bas;
    ipw[maxn] = {fp(pw[maxn].v1, mod[0] - 2, mod[0]), fp(pw[maxn].v2, mod[1] - 2, mod[1])};
    Rof(i, maxn - 1, 0) ipw[i] = ipw[i + 1] * bas; 
    read(n); read(m);
    For(i, 1, n){
        scanf("%s", s + 1);
        int now = 1, len = strlen(s + 1);
        For(j, 1, len){
            if(!ch[now][s[j] - 'a']){
                ch[now][s[j] - 'a'] = ++tot;
                dep[tot] = dep[now] + 1;
                val[tot] = val[now] * bas + (s[j] - 'a' + 1);
            }
            now = ch[now][s[j] - 'a'];
        }
        ok[now]++;
        to[0][i] = now;
    }
    For(i, 1, m){
        scanf("%s", s + 1);
        int now = 2, len = strlen(s + 1);
        For(j, 1, len){
            if(!ch[now][s[j] - 'a']){
                ch[now][s[j] - 'a'] = ++tot;
                dep[tot] = dep[now] + 1;
                val[tot] = val[now] * bas + (s[j] - 'a' + 1);
            }
            now = ch[now][s[j] - 'a'];
        }
        ok[now]++;
        to[1][i] = now;
    }
    build();
    dfs(1, 0); dfs(2, 1);
    dfs1(1, 0); dfs1(2, 1);
    int sum = 0;
    For(i, 1, n) sum += !as[to[0][i]];
    printf("%d ", sum);
    sum = 0;
    For(i, 1, m) sum += !as[to[1][i]];
    printf("%d\n", sum);
	return 0;
}
