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
#define maxn 400000
using namespace std;

int T, a[maxn + 5], b[maxn + 5], n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int st[maxn + 5], top = 0;

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        int mx = 0;
        For(i, 1, n) read(a[i]), mx = max(mx, a[i]);
        For(i, 1, m) read(b[i]);
        sort(b + 1, b + m + 1);
        top = 0;
        For(i, 1, n){
            while(top && a[i] >= a[st[top]]) top--;
            st[++top] = i;
        }
        int now = m;
        For(i, 1, top){
            while(now && b[now] >= a[st[i]]) printf("%d ", b[now--]);
            For(j, st[i - 1] + 1, st[i]) printf("%d ", a[j]);
        }
        while(now) printf("%d ", b[now--]);
        puts("");
    }
}
