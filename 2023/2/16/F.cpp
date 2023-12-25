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

int n, q, a[3][maxn + 5], as[maxn + 5], b[maxn + 5];
vector<pair<int, int> > vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tr[maxn + 5];
void ins(int x, int val){
    while(x <= n) tr[x] += val, x += x & -x;
}
int que(int x){
    int asi = 0;
    while(x) asi += tr[x], x -= x & -x;
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 0, 2) For(j, 1, n){
        char c; cin >> c;
        a[i][j] = c - '0';
    }
    For(i, 1, n) For(j, 0, 2) b[i] |= a[j][i] << j;
    read(q);
    For(i, 1, q){
        int l, r; read(l); read(r);
        vec[l].pb(mp(r, i));
    }
    int to = n + 1;
    Rof(i, n, 1){
        if(b[i] == 0){
            to = n + 1;
        }
        if(b[i] == 1){
            if(!a[0][i + 1]) ins(i + 1, 1);
            to = n + 1;
        }
        if(b[i] == 2){
            if(!a[1][i + 1]) ins(i + 1, 1);
            to = n + 1;
        }
        if(b[i] == 3){
            if(!a[0][i + 1] && !a[1][i + 1]) ins(i + 1, 1);
            to = n + 1;
        }
        if(b[i] == 4){
            if(!a[2][i + 1]) ins(i + 1, 1);
            to = n + 1;
        }
        if(b[i] == 5){
            if(!a[0][i + 1]) ins(i + 1, 1);
            if(!a[2][i + 1]) ins(i + 1, 1);
        }
        if(b[i] == 6){
            if(!a[1][i + 1] && !a[2][i + 1]) ins(i + 1, 1);
            to = n + 1;
        }
        if(b[i] == 7){
            if(!a[0][i + 1] && !a[1][i + 1] && !a[2][i + 1]) ins(i + 1, 1);
            if(b[i + 1] == 5){
                ins(i + 1, -1);
                ins(to, 1);
            }
            to = i;
        }
        int tem = b[i] != 0;
        if(b[i] == 5) tem++;
        ins(i, tem); ins(i + 1, -tem);
        for(auto j : vec[i]) as[j.sec] = que(j.fir);
    }
    For(i, 1, q) printf("%d\n", as[i]);
    return 0;
}
