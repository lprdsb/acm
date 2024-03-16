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

#define maxn 1500
int n, k;
LL get_val(int *x) {
    LL res = 0;
    For(i, 0, k - 1) res = res * 3 + x[i];
    return res;
}
struct Card {
    int fea[30];
    LL val;
    Card() {}
    Card(char *s) {
        For(i, 0, k - 1) {
            int tem = 0;
            if(s[i] == 'E') tem = 1;
            if(s[i] == 'T') tem = 2;
            fea[i] = tem;
        }
        val = get_val(fea);
    }
} car[maxn + 5];

int ff[35];
int main() {
    //freopen("in", "r", stdin);
    read(n); read(k);
    map<LL, int> ma;
    For(i, 1, n) {
        char s[40]; scanf("%s", s);
        car[i] = Card(s);
        ma[car[i].val] = 1;
    }
    int res = 0;
    For(i, 1, n) For(j, 1, n) if(i != j) {
        For(p, 0, k - 1) {
            if(car[i].fea[p] != car[j].fea[p]) ff[p] = 3 - car[i].fea[p] - car[j].fea[p];
            else ff[p] = car[i].fea[p];
        }
        if(ma[get_val(ff)]) res++;
    }
    printf("%d\n", res / 6);
    return 0;
}
