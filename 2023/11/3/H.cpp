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
#define maxn 1000000
#define mod 1000000007
using namespace std;

int n, m;
char s[maxn + 5];

int poi_tot = 0;
struct Poi{
    int sum, cnt;
    Poi *ch[26], *to;
} poi[maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}

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
    read(n); read(m);
    Poi *rt = get_new();
    For(i, 1, n){
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        Poi *now = rt;
        For(j, 1, len){
            if(!now->ch[s[j] - 'a']) now->ch[s[j] - 'a'] = get_new();
            now = now->ch[s[j] - 'a'];
        }
        now->cnt++;
        now->sum += len;
    }
    queue<Poi*> q;
    For(o, 0, 25){
        if(rt->ch[o]){
            rt->ch[o]->to = rt;
            q.push(rt->ch[o]);
        }
        else rt->ch[o] = rt;
    }
    while(q.size()){
        Poi *u = q.front(); q.pop();
        For(o, 0, 25){
            if(u->ch[o]){
                Poi *v = u->ch[o];
                v->to = u->to->ch[o];
                v->cnt += v->to->cnt;
                v->sum = (1ll * v->sum + v->to->sum) % mod;
                q.push(v);
            }
            else u->ch[o] = u->to->ch[o];
        }
    }
    For(i, 1, m){
        LL res = 0;
        Poi *now = rt;
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        For(j, 1, len){
            now = now->ch[s[j] - 'a'];
            res = (res + 1ll * (1ll * now->cnt * (j + 1) - now->sum + mod) % mod * (len - j + 1) % mod) % mod;
        }
        printf("%d\n", res);
    }
    return 0;
}
