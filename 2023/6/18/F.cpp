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

int n, a[maxn + 5], q;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int f[2][maxn + 5];
void add(int ty, int l, int r){
    if(l > r){
        add(ty, l, n - 1);
        add(ty, 0, r);
        return;
    }    
    f[ty][l]++;
    f[ty][r + 1]--;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 0, n - 1) read(a[i]);
    For(i, 0, n - 1) if(a[i] != n){
        add(0, (i + 1) % n, (i - a[i] + n) % n);
        add(1, (i + a[i]) % n, (i - 1 + n) % n);
    }
    For(o, 0, 1) For(i, 1, n - 1) f[o][i] += f[o][i - 1];
    For(i, 0, (n - 1) / 2) swap(f[1][i], f[1][n - 1 - i]);
    int now = 0, o = 0;
    printf("%d\n", f[o][now]);
    read(q);
    while(q--){
        int op, k; read(op);
        if(op == 1){
            read(k);
            now = (now + k) % n;
        }
        else if(op == 2){
            read(k);
            now = (now - k + n) % n;
        }
        else{
            o ^= 1;
            now = (n - now) % n;
        }
        // cout << o << " " << now << endl;
        printf("%d\n", f[o][now]);
    }
    return 0;
}
