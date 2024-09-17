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

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxm 5000000
int n, q, pa_tot = 0;
struct Pair {
    int ty;
    int ch[2];
} pa[maxm + 5];

#define maxn 5000
char s[maxn + 5];

int sol(int rt, int now) {
    int tem = ++pa_tot;
    if(s[now] == 'i') {
        pa[rt].ty = 1;
        return now + 4;
    }
    else if(s[now] == 'd') {
        pa[rt].ty = 2;
        return now + 7;
    }
    else {
        pa[rt].ty = 0;
        pa[rt].ch[0] = ++pa_tot;
        now += 5;
        now = sol(pa_tot, now);
        pa[rt].ch[1] = ++pa_tot;
        now = sol(pa_tot, now);
        return now + 1;
    }
}

string sss;
unordered_map<string, int> ma;

void output(int rt) {
    if(pa[rt].ty == 0) {
        printf("pair<");
        output(pa[rt].ch[0]);
        printf(",");
        output(pa[rt].ch[1]);
        printf(">");
    }
    else if(pa[rt].ty == 1) printf("int");
    else printf("double");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) {
        scanf("%s", s + 1);
        int len = strlen(s + 1), tem = ++pa_tot;
        sol(tem, 1);
        // output(tem); puts("");
        cin >> sss; sss.pop_back();
        ma[sss] = tem;
    }
    For(i, 1, q) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        sss = "";
        int now = 1;
        while(now <= len && s[now] != '.') {
            sss += s[now];
            now++;
        }
        int rt = ma[sss]; now++;
        // output(rt); puts("");
        while(now <= len) {
            if(s[now] == 'f') rt = pa[rt].ch[0], now += 6;
            else if(s[now] == 's') rt = pa[rt].ch[1], now += 7;
        }
        output(rt); puts("");
    }
}
