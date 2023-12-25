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

int n, t;
LL lhs[maxn + 5], rhs[maxn + 5], a[maxn + 5], okl[maxn + 5], okr[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int get_bit(LL x){
    int res = 0;
    x >>= 1;
    while(x) res++, x >>= 1;
    return res;
}

void upd(int l, int r, LL val){
    if(val){
        int tem = get_bit(val);
        lhs[r] |= 1ll << tem;
        rhs[l] |= 1ll << tem;
    }
    else okl[l] = okr[r] = 1;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n) read(a[i]), a[i] ^= a[i - 1];
        if(n == 1){
            puts("1");
            continue;
        }
        upd(1, n, a[n]);
        Rof(i, n - 1, 1){
            For(j, 1, n - i + 1){
                if(okl[j] || okr[j + i - 1] || ((a[j + i - 1] ^ a[j - 1]) & (rhs[j] | lhs[j + i - 1]))){
                    if(i != 1) upd(j, j + i - 1, a[j + i - 1] ^ a[j - 1]);
                    else printf("1");
                }
                else if(i == 1) printf("0");
            }
        }
        puts("");
        For(i, 1, n) lhs[i] = rhs[i] = okl[i] = okr[i] = 0;
    }
}
