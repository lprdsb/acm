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

int n;
char s[maxn + 5];
int poi_tot = 0;
struct Poi{
    int len, cnt;
    Poi *ch[26], *to;
} poi[maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
struct Tree{
    Poi *Rt[2];
    Tree(){
        Rt[0] = get_new();
        Rt[1] = get_new();
        Rt[0]->to = Rt[1]->to = Rt[1];
        Rt[1]->len = -1;
    }
    Poi *get_o(Poi *rt, int o){
        if(!rt->ch[o]) return Rt[0];
        return rt->ch[o];
    }
    Poi* ins(Poi *las, int pos){
        int o = s[pos] - 'a';
        while(s[pos - las->len - 1] != s[pos]) las = las->to;
        if(las->ch[o]) return las->ch[o];
        else{
            Poi *now = get_new(), *pre = las->to;
            now->len = las->len + 2;
            while(s[pos - pre->len - 1] != s[pos]) pre = pre->to;
            pre = get_o(pre, o);
            now->to = pre;
            now->cnt = pre->cnt + 1;
            las->ch[o] = now;
            return now;
        }
    }
} tr;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    scanf("%s", s + 1); n = strlen(s + 1);
    int res = 0;
    Poi *las = tr.Rt[0];
    For(i, 1, n) tr.ins(las, i);
    return 0;
}
