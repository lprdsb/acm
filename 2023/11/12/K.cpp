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
using namespace std;

int n, q;
int poi_tot = 0;
struct Poi{
    Poi *ch[26];
    int cnt, fin;
} poi[2 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

char s[maxn + 5];

LL ma[30][30], res = 0;

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(q);
    Poi *Rt = get_new();
    For(i, 1, n){
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        Poi *now = Rt;
        For(j, 1, len){
            int o = s[j] - 'a';
            For(p, 0, 25) if(p != o && now->ch[p]) ma[o][p] += now->ch[p]->cnt;
            now = get_o(now, o);
            now->cnt++;
        }
        now->fin++;
        res += now->cnt - now->fin;
    }
    // cout << ma[0][2] << endl;
    while(q--){
        LL resi = 0;
        scanf("%s", s + 1);
        For(i, 1, 26) For(j, i + 1, 26) resi += ma[s[i] - 'a'][s[j] - 'a'];
        printf("%lld\n", res + resi);
    }
    return 0;
}
