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
#define maxn 3000
using namespace std;

int t, n, a[maxn + 5], b[maxn + 5], fa, fb, as[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int ta[maxn + 5];
void sol(int x){
    if(x > n) return;
    as[++as[0]] = x;
    For(i, 1, n){
        ta[i] = a[i];
        if(i + x >= 1 && i + x <= n) ta[i] ^= a[i + x];
    }
    For(i, 1, n) a[i] = ta[i];
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    int tt = t;
    while(t--){
        fa = fb = 0;
        read(n);
        For(i, 1, n){
            char c; cin >> c;
            a[i] = c - '0';
            if(!fa && a[i]) fa = i;
        }
        For(i, 1, n){
            char c; cin >> c;
            b[i] = c - '0';
            if(!fb && b[i]) fb = i;
        }
        if(!fa){
            if(!fb) puts("0");
            else puts("-1");
        }
        else if(!fb) puts("-1");
        else{
            as[0] = 0;
            if(fa > fb) sol(fa - fb), fa = fb;
            For(i, fa + 1, n) if(a[i] != b[i]) sol(fa - i);
            if(fa != fb){
                Rof(i, n, fa) if(a[i]){
                    Rof(j, fa, 1) if(a[j] != b[j]) sol(i - j);
                    break;
                }
            }
            printf("%d\n", as[0]);
            For(i, 1, as[0]) printf("%d ", as[i]); puts("");
        }
    }
    return 0;
}
